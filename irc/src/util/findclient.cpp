/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findclient.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:45:28 by kuvarti           #+#    #+#             */
/*   Updated: 2023/04/19 14:58:59 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "clients.hpp"

/*
template<typename T>
std::vector<Clients>::iterator	util::findnclient(std::vector<Clients> &map, T(Clients::*func)(void), const Clients &cli, T asd)
{
	std::vector<Clients>::iterator	ret = map.begin();
	for (; ret != map.end() ; ret++)
	{
		if (ret->*func() == asd)
			break;
	}
	return (ret);
}
*/

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

std::vector<Clients>::iterator	util::findnick(std::vector<Clients> &cli, std::string nick)
{
	std::vector<Clients>::iterator ret = cli.begin();
	for (; ret != cli.end(); ret++)
	{
		if (ret->getnickname() == nick)
			break;
	}
	return (ret);
}
