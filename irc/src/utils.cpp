/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:53:18 by root              #+#    #+#             */
/*   Updated: 2023/04/17 11:20:47 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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