/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:00 by root              #+#    #+#             */
/*   Updated: 2023/04/15 13:09:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	Server	srv;

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