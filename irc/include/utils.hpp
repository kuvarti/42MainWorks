/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:44:04 by root              #+#    #+#             */
/*   Updated: 2023/04/17 11:14:23 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <poll.h>
#include <vector>

class util{
public:
	static	std::vector<struct pollfd>::iterator	findsocket(std::vector<struct pollfd> &,const struct pollfd &);
};

int	operator<<(std::vector<struct pollfd> &, const struct pollfd &);