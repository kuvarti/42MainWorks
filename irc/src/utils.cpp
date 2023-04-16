/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:18 by root              #+#    #+#             */
/*   Updated: 2023/04/16 19:10:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::vector<struct pollfd>::iterator	util::findsocket(std::vector<struct pollfd> &vec,const struct pollfd &str)
{
	std::vector<struct pollfd>::iterator	ret = vec.begin();
	for (; ret < vec.end(); ret++)
	{
		if (ret->fd == str.fd)
			return ret;
	}
	return ((std::vector<struct pollfd>::iterator)0);
}