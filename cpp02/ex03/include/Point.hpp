/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:24:32 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/04 23:32:42 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{
public:
	Point();
	Point(float const &, float const &);
	Point & operator=(Point const &);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

private:
	Fixed const x;
	Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
