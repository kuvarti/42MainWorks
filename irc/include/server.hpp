/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:45:53 by root              #+#    #+#             */
/*   Updated: 2023/04/15 16:36:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <netinet/in.h>
#include <sys/socket.h>
#include <poll.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <map>

#include "clients.hpp"

#define PORT 4242
#define BSIZE 512

class Server{
public:
	Server();
	~Server();

	void	loop();
	void	recvmessage(struct pollfd);

private:
	std::vector<pollfd>	_socks;
	std::vector<Clients>			cli;
};