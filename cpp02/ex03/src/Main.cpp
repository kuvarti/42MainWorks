/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:57:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/07 22:15:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void )
{
	Point a(3, 5);
	Point b(1, 1);
	Point c(5, 1);

	//false
	std::cout << "t" << bsp(a, b, c, Point(3, 3)) << std::endl;
	//True
	std::cout << "x" << bsp(a, b, c, Point(1, 3)) << std::endl;

	return 0;
}
