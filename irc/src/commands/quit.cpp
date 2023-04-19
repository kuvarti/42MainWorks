/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:54:04 by kuvarti           #+#    #+#             */
/*   Updated: 2023/04/19 16:10:43 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Messages::quit(struct pollfd sock,  Server &srv, std::vector<std::string> str)
{
	srv.sendmessage(sock, util::msgSender(str));
	srv.removesock(sock);
}