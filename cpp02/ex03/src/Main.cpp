/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 02:57:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/04 23:58:06 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main( void )
{
	Point a(1, 1);
	Point b(2, 2);

	std::cout << a.getRange(b).toFloat() << std::endl;

	return 0;
}
