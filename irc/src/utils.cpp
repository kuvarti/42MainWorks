/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuvarti <kuvarti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:18 by root              #+#    #+#             */
/*   Updated: 2023/04/19 16:10:09 by kuvarti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
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

std::map <std::string, void(*)(struct pollfd,  Server &, std::vector<std::string>)> Messages::fillcommands(){
	std::map <std::string, void(*)(struct pollfd,  Server &, std::vector<std::string>)> ret;
	ret["NICK"] = &Messages::nick;
	ret["ERROR"] = &Messages::error;
	ret["PASS"] = &Messages::pass;
	ret["CAP"] = &Messages::cap;
	ret["QUIT"] = &Messages::quit;
	//ret["USER"] = &Messages::user;
	return ret;
}

std::string	util::msgSender(std::vector<std::string> vc)
{
	std::string	ret;

	for (std::vector<std::string>::iterator it = vc.begin(); it != vc.end(); it++)
		ret += (*it) + " ";
	return ret;
}

std::vector<std::string>	util::msgCreator(std::string prefix, std::string msg)
{
	std::vector<std::string>	ret;
	ret.push_back(prefix);
	msg = ":" + msg;
	ret.push_back(msg);
	return ret;
}