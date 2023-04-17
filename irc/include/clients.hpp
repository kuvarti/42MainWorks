/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:04:18 by root              #+#    #+#             */
/*   Updated: 2023/04/18 00:29:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <poll.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>

#define	UNCONFIRMED "unconfirmed"
#define	UNREGISTERED "unregistered"

class Clients{
public:
	Clients(int);
	~Clients();

	void	setnickname(std::string nick) { _nickname = nick; }

	int	getclientsock() const { return _client.fd; };
	std::string	getnickname() const { return _nickname; };
private:
	std::string			_nickname;
	struct pollfd		_client;
	struct sockaddr_in	clientaddr;
};