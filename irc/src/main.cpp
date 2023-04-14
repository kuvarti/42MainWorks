/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:51:00 by root              #+#    #+#             */
/*   Updated: 2023/04/14 23:40:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <string.h>

#define port 6667
using namespace std;

int main()
{
	int bir = 1;
	int	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &bir, sizeof(bir)))
		exit(EXIT_FAILURE);
	cout << sockfd << endl;
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
	struct sockaddr_in clientaddr;
	socklen_t cliaddressize = sizeof(clientaddr);
	int clientsock = accept(sockfd, (struct sockaddr*) &clientaddr, &cliaddressize);
	if (clientsock < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		char buffer[512];
		bzero(buffer, 512);
		ssize_t numbytesreceived = recv(clientsock, buffer, 512, 0);
		if (numbytesreceived < 0)
			exit(EXIT_FAILURE);
		if (!strncmp(buffer, "exit()", strlen("exit()")))
		{
			close(clientsock);
			break;
		}
		ssize_t numbytessent = send(clientsock, "ula sen kime sekil yapiyun heeee\n", 34, 0);
		if (numbytessent < 0)
			exit(EXIT_FAILURE);
	}
	shutdown(sockfd, SHUT_RDWR);
	close(sockfd);
}