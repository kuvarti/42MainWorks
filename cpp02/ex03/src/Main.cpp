/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:57:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 05:46:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void )
{
	Point a(5, 7);
	Point b(4, 1);
	Point c(5, 1);

	//false
	std::cout << bsp(a, b, c, Point(1, 1)) << std::endl;
	//True
	std::cout << bsp(a, b, c, Point(4.5f, 1.1f)) << std::endl;

	return 0;
}
