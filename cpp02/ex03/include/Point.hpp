/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:24:32 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 00:01:36 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point{
public:
	Point();
	Point(float const &, float const &);
	Point(Point const &);
	Point & operator=(Point const &);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

	Fixed getRange(Point const &) const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
