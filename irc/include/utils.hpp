/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:44:04 by root              #+#    #+#             */
/*   Updated: 2023/04/18 00:22:39 by root             ###   ########.fr       */
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
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &map, const int &poll);
	static	std::vector<Clients>::iterator	findclient(std::vector<Clients> &, const struct pollfd &);
};

int	operator<<(std::vector<struct pollfd> &, const struct pollfd &);