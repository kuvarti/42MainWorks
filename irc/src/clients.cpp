/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:19:06 by root              #+#    #+#             */
/*   Updated: 2023/04/17 17:34:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clients.hpp"

Clients::Clients(int sock) : _nickname(UNCONFIRMED)
{
	struct sockaddr_in	clientaddr;
	socklen_t	slen = sizeof(clientaddr);
	_client.fd = accept(sock, (struct sockaddr*)&clientaddr, &slen);
	if (_client.fd < 0)
		exit(EXIT_FAILURE);
}

Clients::~Clients()
{
}