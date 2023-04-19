/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:03:37 by kuvarti           #+#    #+#             */
/*   Updated: 2023/04/19 16:08:05 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Messages::error(struct pollfd sock, Server &srv, std::vector<std::string> token)
{
	srv.sendmessage(sock, util::msgSender(token));
}