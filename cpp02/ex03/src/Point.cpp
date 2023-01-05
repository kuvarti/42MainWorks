/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:27:14 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 05:38:12 by aeryilma         ###   ########.fr       */
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

std::ostream & operator<<(std::ostream &o, const Point &p)
{
	o << "(x:" << p.getX() << ", y:" << p.getY() << ")";
	return o;
}


Point & Point::operator=(Point const & p)
{
	(void)p;
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
