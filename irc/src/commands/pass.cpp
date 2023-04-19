/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:14:31 by kuvarti           #+#    #+#             */
/*   Updated: 2023/04/19 16:13:34 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <iostream>

void	Messages::pass(struct pollfd sock, Server &srv, std::vector<std::string> token)
{
	std::vector<Clients>::iterator it = util::findclient(srv.getclient(), sock);
	if (it == srv.getclient().end())
		return ;
	if (token[1] != srv.getpass())
	{
		Messages::error(sock, srv, util::msgCreator("ERROR", "incorrect Password."));
		Messages::quit(sock, srv, util::msgCreator("QUIT", "Disconnecting()"));
		return ;
	}
	(*it).setconfirmed(true);
}