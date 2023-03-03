/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 06:15:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/03 06:19:52 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
public:
	using iterator = typename std::deque<T>::iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};
