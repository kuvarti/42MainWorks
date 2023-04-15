/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clients.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:04:18 by root              #+#    #+#             */
/*   Updated: 2023/04/15 13:28:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>

class Clients{
public:
	Clients(int);
	~Clients();

	int	getclientsock() const { return clientsock; };
private:
	int					clientsock;
	struct sockaddr_in	clientaddr;
};