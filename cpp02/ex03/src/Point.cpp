/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:27:14 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/04 23:33:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0), y(0)
{ }

Point::Point(float const &x, float const &y):x(x), y(y)
{ }

Point::~Point()
{ }

Point & Point::operator=(Point const &p)
{
	if (this != &p)
	{
		this->x = p.getX();
		this->y = p.getY();
	}
	return *this;
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}
