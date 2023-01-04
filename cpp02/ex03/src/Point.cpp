/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:27:14 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 00:48:30 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():_x(0), _y(0)
{ }

Point::Point(float const &x, float const &y) : _x(x), _y(y)
{ }

Point::Point(Point const &p) : _x(p.getX()), _y(p.getY())
{ }

Point::~Point()
{ }

Point & Point::operator=(Point const & p)
{
	if (this != &p)
	{
		_x = const_cast<Fixed>(p._x);
		_y = const_cast<Fixed>(p._y);
	}
	return *this;
}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}

Fixed Point::getRange(Point const &p) const
{
	Fixed x = this->_x - p.getX();
	Fixed y = this->_y - p.getY();
	return (x * x + y * y);
}
