/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:53 by root              #+#    #+#             */
/*   Updated: 2023/04/18 00:27:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <poll.h>

#include <algorithm>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <utility>
#include <map>

#include "utils.hpp"
#include "clients.hpp"

#define BSIZE 512
class Channel;
class Server;

class Messages{
public:
	static std::map <std::string, void(*)(int, Server &, std::vector<std::string>)> fillcommands();

	static void	user(int, Server &, std::vector<std::string>);
	static void	nick(int, Server &, std::vector<std::string>);
	static void	join(int, Server &, std::vector<std::string>);
};

class Server{
public:
	Server(int, std::string);
	~Server();

	void	loop();
	void	recvmessage(struct pollfd &);
	void	sendmessage(struct pollfd &, char *);
	void	sendmessage(struct pollfd &, std::vector<std::string>);
	std::vector<std::string>	parsemessage(struct pollfd &, char *);

	std::vector<Clients> &getclient() { return _cli; }

private:
	void	removesock(struct pollfd &);

	std::string		_password;
	int				_sock;
	std::vector<pollfd>		_socks;
	std::vector<Clients>	_cli;
	std::map <std::string, void(*)(int, Server &, std::vector<std::string>)> commands;
};