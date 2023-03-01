/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:11:52 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 17:27:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T1>
void swap(T1 &a, T1 &b) {
	T1	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T1>
T1	min(T1 a, T1 b) {
	if (a < b)
		return a;
	return b;
}

template<typename T1>
T1	max(T1 a, T1 b) {
	if (a > b)
		return a;
	return b;
}
