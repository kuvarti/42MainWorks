/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 05:40:42 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 05:41:17 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();
	Fixed x = point.getX();
	Fixed y = point.getY();

	Fixed d1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
	Fixed d2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
	Fixed d3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);

	if (d1 >= 0 && d2 >= 0 && d3 >= 0)
		return true;
	else if (d1 <= 0 && d2 <= 0 && d3 <= 0)
		return true;
	else
		return false;
}
