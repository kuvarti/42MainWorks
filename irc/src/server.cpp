/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:48 by root              #+#    #+#             */
/*   Updated: 2023/04/19 17:25:49 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <stdlib.h>
#include <iostream>

//*	Can be delete this \/ \/
void	debugparsing(std::vector<std::string> str)
{
	int j = 0;
	if (str.size() > 0)
		std::cout << "Parsed messages; " << std::endl;
	for (std::vector<std::string>::iterator i = str.begin(); i < str.end(); i++)
	{
		std::cout << j++ << ". : " << (*i) << std::endl;
	}
	if (str.size() > 0)
		std::cout << "-=-=-=-=-=-=-=-" << std::endl;
}
void	showclients(std::vector<Clients> &cli )
{
	std::cout << std::endl << "Clients:" << std::endl;
	for (size_t i = 0; i < cli.size(); i++)
	{
		std::cout << "Client " << i << " nickname: " << cli[i].getnickname() << std::endl;
	}
	std::cout << "------------" << std::endl;
}
//*	Can be delete this /\ /\

Server::Server(int port, std::string pass) : _password(pass)
{
	std::cout << "Initializing server..." << std::endl;
	int opt = 1;
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
		exit(EXIT_FAILURE);
	struct sockaddr_in sockaddin;
	sockaddin.sin_family = AF_INET;
	sockaddin.sin_addr.s_addr = INADDR_ANY;
	sockaddin.sin_port = htons(port);
	if (bind(_sock, (struct sockaddr*) &sockaddin, sizeof(sockaddin)) == -1)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}
	if (listen(_sock, 5) == -1)
		exit(EXIT_FAILURE);
	commands = Messages::fillcommands();
	_socks.push_back((pollfd){_sock, POLLIN | POLLOUT, POLLIN | POLLOUT});
	std::cout << "Server running on port:" << port << std::endl;
}

void	Server::loop()
{
	Clients	*tmp;
	int		pollrs;
	while (1)
	{
		showclients(_cli);	//* This is Debug function
		pollrs = poll(_socks.begin().base(), _socks.size(), -1);
		if (pollrs < 0)
			exit(EXIT_FAILURE);
		else if (pollrs == 0)
			continue;
		for (size_t i = 0; i < _socks.size(); i++)
		{
			if (_socks[i].revents & POLLIN)
			{
				if (_socks[i].fd == _socks[0].fd)
				{
					tmp = new Clients(_socks[i].fd);
					_cli.push_back(*tmp);
					_socks.push_back((pollfd){(*tmp).getclientsock(), POLLIN, 0});
					std::cout << "New Connection appeared." << std::endl;
				}
				else
					recvmessage(_socks[i]);
			}
			if (_socks[i].revents & POLLHUP)
			{
				removesock(_socks[i]);
			}
		}
	}
}

void	Server::recvmessage(struct pollfd &sock)
{
	char	buffer[BSIZE];
	bzero(buffer, BSIZE);
	if (recv(sock.fd, buffer, BSIZE, 0) < 0)
	{
		std::cerr << "some error appeared" << std::endl;
		return ;
	}
	debugparsing(parsemessage(sock, buffer));
}

std::vector<std::string>	Server::parsemessage(struct pollfd &sock, char *buffer)
{
	std::vector<std::string> ret;
	std::string tmp;
	for (size_t i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == ' ' || buffer[i] == '\r')
		{
			if (!(tmp.length() > 0))
				continue ;
			std::cout << "i'll take this : " << tmp << std::endl;
			ret.push_back(tmp);
			tmp.clear();
		}
		else if (buffer[i] == '\n')
		{
			if (!(ret.size() > 0))
				continue;
			std::cout << "I'll send this" <<std::endl;
			debugparsing(ret);
			if (!messageexecuter(sock, ret))
				return ret;
			ret.clear();
		}
		else
			tmp += buffer[i];
	}
	if (ret.size() > 0)
		messageexecuter(sock, ret);
	return ret;
}

int	Server::messageexecuter(struct pollfd &sock, std::vector<std::string> token)
{
	std::map<std::string, void(*)(struct pollfd,  Server &, std::vector<std::string>)>::iterator	it;
	it = commands.find(token[0]);
	if (it == commands.end())
	{
		Messages::error(sock, *this, util::msgCreator("ERROR", "This command unavailable."));
		return 1;
	}
	std::vector<Clients>::iterator it2 = util::findclient(getclient(), sock);
	if (token[0] != "PASS" && token[0] != "CAP" && (*it2).isconfirmed() == false)
	{
		Messages::error(sock, *this, util::msgCreator("ERROR", "This user not confirmed."));
		Messages::quit(sock, *this, util::msgCreator("QUIT", "Disconnecting()"));
		return 1;
	}
	it->second(sock, *this, token);
	return (0);
}

void	Server::sendmessage(struct pollfd &sock, std::string str)
{
	str += "\r\n";

	int error_code;
	socklen_t error_code_size = sizeof(error_code);
	getsockopt(sock.fd, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
	if (error_code == 0)
		send(sock.fd, str.c_str(), str.size(), 0);
	else{
		std::cout << "A connection is down" << std::endl;
		removesock(sock);
	}
}

void	Server::removesock(struct pollfd &sock)
{
	std::vector<struct pollfd>::iterator it = util::findsocket(_socks, sock);
	if (it != _socks.end())
		_socks.erase(it);
	std::vector<Clients>::iterator it2 = util::findclient(_cli, sock);
	if (it2 != _cli.end())
		_cli.erase(it2);
}

Server::~Server()
{
	std::cout << "Server Closing..." << std::endl;
	shutdown(_socks[0].fd, SHUT_RDWR);
	close(_socks[0].fd);
	std::cout << "Server port closed" << std::endl;
	std::cout << "Server Closed()" << std::endl;
}
