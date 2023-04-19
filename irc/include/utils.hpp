/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:44:04 by root              #+#    #+#             */
/*   Updated: 2023/04/19 16:05:02 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <poll.h>
#include <vector>
#include <string>
#include <map>

class Clients;

class util{
public:
	static	std::vector<struct pollfd>::iterator	findsocket(std::vector<struct pollfd> &,const struct pollfd &);
//todo bu template bitecek!
//	template<typename T>
//	static	std::vector<Clients>::iterator	findnclient(std::vector<Clients> &, T(Clients::*)(void), const Clients &, T);
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &map, const int &poll);
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &, const struct pollfd &);
	static	std::vector<Clients>::iterator	findnick(std::vector<Clients> &, std::string);

	static	std::vector<std::string>	msgCreator(std::string, std::string);
	static	std::string	msgSender(std::vector<std::string>);
};

int	operator<<(std::vector<struct pollfd> &, const struct pollfd &);