/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:18 by root              #+#    #+#             */
/*   Updated: 2023/04/18 00:22:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "clients.hpp"

std::vector<struct pollfd>::iterator	util::findsocket(std::vector<struct pollfd> &vec,const struct pollfd &str)
{
	std::vector<struct pollfd>::iterator	ret = vec.begin();
	for (; ret < vec.end(); ret++)
	{
		if (ret->fd == str.fd)
			break ;
	}
	return (ret);
}

std::vector<Clients>::iterator	util::findclient(std::vector<Clients> &map, const struct pollfd &poll)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->getclientsock() == poll.fd)
			break;
	}
	return (ret);
}

std::vector<Clients>::iterator	util::findclient(std::vector<Clients> &map, const int &poll)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->getclientsock() == poll)
			break;
	}
	return (ret);
}