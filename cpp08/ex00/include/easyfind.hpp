/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:15:20 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/02 01:36:27 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>

class outrange : public std::exception{
public:
	const char *what() const throw()
	{
		return "Out of range";
	}
};

template <typename T>
typename T::iterator	easyfind(T &p1, int p2){
	typename T::iterator ret = std::find(p1.begin(), p1.end(), p2);
	if (ret == p1.end())
		throw outrange();
	return ret;
}
