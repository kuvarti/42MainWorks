/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:31:17 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 17:45:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T>
void	iter(T arr[], size_t len, void (fun)(T &)) {
	for (size_t i = 0; i < len; i++)
	{
		fun(arr[i]);
	}
}
