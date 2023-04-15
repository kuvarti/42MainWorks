/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:19:06 by root              #+#    #+#             */
/*   Updated: 2023/04/15 13:53:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clients.hpp"

Clients::Clients(int sock)
{
	socklen_t	slen = sizeof(clientaddr);
	clientsock = accept(sock, (struct sockaddr*)&clientaddr, &slen);
	if (clientsock < 0)
		exit(EXIT_FAILURE);
}

Clients::~Clients()
{
}