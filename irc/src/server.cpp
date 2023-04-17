/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:48 by root              #+#    #+#             */
/*   Updated: 2023/04/17 13:04:16 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <stdlib.h>
#include <iostream>

Server::Server(int port)
{
	std::cout << "Initializing server..." << std::endl;
	int opt = 1;
	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
		exit(EXIT_FAILURE);
	struct sockaddr_in sockaddin;
	sockaddin.sin_family = AF_INET;
	sockaddin.sin_addr.s_addr = INADDR_ANY;
	sockaddin.sin_port = htons(port);
	if (bind(sockfd, (struct sockaddr*) &sockaddin, sizeof(sockaddin)) == -1)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if (listen(sockfd, 5) == -1)
		exit(EXIT_FAILURE);
	_socks.push_back((pollfd){sockfd, POLLIN | POLLOUT, POLLIN | POLLOUT});
	std::cout << "Server running on port:" << port << std::endl;
}

void	Server::loop()
{
	Clients	*tmp;
	int		pollrs;
	while (1)
	{
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
					cli.push_back(*tmp);
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

void	socklist(std::vector<struct pollfd> &socks)
{
	std::cout << "Socket list:" << std::endl;
	for (size_t i = 0; i < socks.size(); i++)
		std::cout << socks[i].fd << std::endl;
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
	std::cout << "Message received from :" << sock.fd << std::endl << buffer << std::endl;
	sendmessage(sock, buffer);
}

void	Server::sendmessage(struct pollfd &sock, char *msg)
{
	int error_code;
	socklen_t error_code_size = sizeof(error_code);
	getsockopt(sock.fd, SOL_SOCKET, SO_ERROR, &error_code, &error_code_size);
	if (error_code == 0)
		send(sock.fd, msg, BSIZE, 0);
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
}

Server::~Server()
{
	std::cout << "Server Closing..." << std::endl;
	shutdown(_socks[0].fd, SHUT_RDWR);
	close(_socks[0].fd);
	std::cout << "Server port closed" << std::endl;
	std::cout << "Server Closed()" << std::endl;
}