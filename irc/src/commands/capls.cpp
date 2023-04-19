/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capls.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:07:11 by kuvarti           #+#    #+#             */
/*   Updated: 2023/04/19 13:24:13 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	Messages::cap(struct pollfd fd, Server &srv, std::vector<std::string> token)
{
	(void)token;
	srv.sendmessage(fd, "");
}