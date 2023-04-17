/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:53 by root              #+#    #+#             */
/*   Updated: 2023/04/17 11:09:34 by aeryilma         ###   ########.fr       */
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
#include <map>

#include "utils.hpp"
#include "clients.hpp"

#define BSIZE 512

class Server{
public:
	Server(int);
	~Server();

	void	loop();
	void	recvmessage(struct pollfd &);
	void	sendmessage(struct pollfd &, char *);

private:
	std::vector<pollfd>	_socks;
	std::vector<Clients>			cli;
	void	removesock(struct pollfd &);
};