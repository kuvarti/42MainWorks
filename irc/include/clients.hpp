/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:04:18 by root              #+#    #+#             */
/*   Updated: 2023/04/19 14:52:26 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <poll.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string>

#define	UNCONFIRMED "unconfirmed"	//password
#define	UNREGISTERED "unregistered"	//nickname

class Clients{
public:
	Clients(int);
	~Clients();

	void	setnickname(std::string nick) { _nickname = nick; }

	int			getclientsock() const { return _client.fd; };
	std::string	getnickname() { return _nickname; };

	bool	isconfirmed() const { return confirmed; };
	bool	isregistered() const { return registered; };

	void	setconfirmed(bool b) { confirmed = b; };
	void	setregistered(bool b) { registered = b; };
private:
	bool				confirmed;
	bool				registered;
	std::string			_nickname;
	struct pollfd		_client;
	struct sockaddr_in	clientaddr;
};