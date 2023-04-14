/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:48 by root              #+#    #+#             */
/*   Updated: 2023/04/14 22:57:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

Server::Server()
{
	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		exit(EXIT_FAILURE);
	if (setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 0, 0))
		exit(EXIT_FAILURE);
	_addr.sin_family = AF_INET;
	_addr.sin_addr.s_addr = INADDR_ANY;
	_addr.sin_port = htons(PORT);
	if (bind(_socket, (struct sockaddr *) &_addr, sizeof(_addr)) < 0)
		exit(EXIT_FAILURE);
	if (listen(_socket, 5) < 0)
		exit(EXIT_FAILURE);
	int client;
	if ((client = accept(_socket, (struct sockaddr *) &_addr, (socklen_t *)sizeof(_addr))) < 0)
		exit(EXIT_FAILURE);
	char buffer[512];
	int valread = recv(client, buffer, 512, 0);
	
}