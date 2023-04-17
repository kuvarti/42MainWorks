/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:00 by root              #+#    #+#             */
/*   Updated: 2023/04/17 15:54:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << "Wrong use plase run with : ./ircserv <port> <password>" << std::endl;
		return 1;
	}
	Server	srv(stoi(argv[1]), argv[2]);

	srv.loop();

	//struct sockaddr_in clientaddr;
	//int clientsock = accept(sockfd, (struct sockaddr*) &clientaddr, &cliaddressize);
	//if (clientsock < 0)
	//	exit(EXIT_FAILURE);
	//while (1)
	//{
	//	char buffer[512];
	//	bzero(buffer, 512);
	//	ssize_t numbytesreceived = recv(clientsock, buffer, 512, 0);
	//	if (numbytesreceived < 0)
	//		exit(EXIT_FAILURE);
	//	if (!strcmp(buffer, "exit()\r\n"))
	//	{
	//		close(clientsock);
	//		break;
	//	}
	//	ssize_t numbytessent = send(clientsock, "ula sen kime sekil yapiyun heeee\n", 34, 0);
	//	if (numbytessent < 0)
	//		exit(EXIT_FAILURE);
	//}
}