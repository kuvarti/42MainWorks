/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:44:04 by root              #+#    #+#             */
/*   Updated: 2023/04/16 19:02:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <poll.h>
#include <vector>

class util{
public:
	static	std::vector<struct pollfd>::iterator	findsocket(std::vector<struct pollfd> &,const struct pollfd &);
};