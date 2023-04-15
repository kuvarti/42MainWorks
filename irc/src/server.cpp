/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:48 by root              #+#    #+#             */
/*   Updated: 2023/04/15 16:42:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <stdlib.h>
#include <iostream>

Server::Server()
{
	std::cout << "Initializing server...";
	int opt = 1;
	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
		exit(EXIT_FAILURE);
	struct sockaddr_in sockaddin;
	sockaddin.sin_family = AF_INET;
	sockaddin.sin_addr.s_addr = INADDR_ANY;
	sockaddin.sin_port = htons(PORT);
	if (bind(sockfd, (struct sockaddr*) &sockaddin, sizeof(sockaddin)) == -1)
	{
		perror("bind");
		exit(EXIT_FAILURE);
	}

	if (listen(sockfd, 5) == -1)
		exit(EXIT_FAILURE);
	_socks.push_back((pollfd){sockfd, POLLIN | POLLOUT, POLLIN | POLLOUT});
	std::cout << "Done!" << std::endl;
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
		for (int i = 0; i < _socks.size(); i++)
		{
			if (_socks[i].revents & POLLIN)
			{
				if (_socks[i].fd == _socks[0].fd)
				{
					tmp = new Clients(_socks[i].fd);
					cli.push_back(*tmp);
					_socks.push_back((pollfd){(*tmp).getclientsock(), POLLIN});
					std::cout << "New Connection appeared." << std::endl;
				}
				else
					recvmessage(_socks[i]);
			}
			if (_socks[i].revents & POLLHUP)
			{
				std::cout << "someone disconnected!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
			}
		}
	}
}

void	Server::recvmessage(struct pollfd sock)
{
	char	buffer[BSIZE];
	bzero(buffer, BSIZE);
	if (recv(sock.fd, buffer, BSIZE, 0) < 0)
	{
		std::cerr << "some error appeared" << std::endl;
		return ;
	}
	send(sock.fd, "i get it! be cool.\n", 20, 0);
}

Server::~Server()
{
	std::cout << "Server Closing..." << std::endl;
	shutdown(_socks[0].fd, SHUT_RDWR);
	close(_socks[0].fd);
	std::cout << "Server port closed" << std::endl;
	std::cout << "Server Closed()" << std::endl;
}