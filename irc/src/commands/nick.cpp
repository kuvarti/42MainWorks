/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:18:22 by root              #+#    #+#             */
/*   Updated: 2023/04/18 00:30:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Messages::nick(int fd, Server &srv, std::vector<std::string> msg)
{
	std::vector<Clients>::iterator	cli = util::findclient(srv.getclient(), fd);
	(*cli).setnickname(msg[1]);
}