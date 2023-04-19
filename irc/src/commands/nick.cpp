/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:18:22 by root              #+#    #+#             */
/*   Updated: 2023/04/19 16:11:20 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Messages::nick(struct pollfd fd,  Server &srv, std::vector<std::string> msg)
{
	std::vector<Clients>::iterator	cli = util::findclient(srv.getclient(), fd);
	if (util::findnick(srv.getclient(), msg[1]) != srv.getclient().end())
	{
		Messages::error(fd, srv, util::msgCreator("ERROR", "This Nickname Already Taken"));
		return ;
	}
	(*cli).setnickname(msg[1]);
	(*cli).setregistered(true);
}