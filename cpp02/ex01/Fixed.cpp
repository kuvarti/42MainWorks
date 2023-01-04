/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:47:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/04 21:06:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// *-*-*-*-*- Constructors -*-*-*-*-*
// Default Constructor
Fixed::Fixed() : _rawbits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &f) : _rawbits(f.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Fixed & Fixed::operator =(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		_rawbits = f.getRawBits();
	return *this;
}

// Integer Constructor
Fixed::Fixed(const int raw) : _rawbits(raw << _fractional_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

// Float Constructor
Fixed::Fixed(const float raw) : _rawbits(roundf(raw * (1 << _fractional_bits)))
{
	std::cout<< "Float constructor called" << std::endl;
}

// *-*-*-*-*- Member Functions -*-*-*-*-*

// *- Overload Operators -*

std::ostream & operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return o;
}

// *- Getter Functions -*

int	Fixed::toInt() const
{
	return (getRawBits() >> _fractional_bits);
}

float	Fixed::toFloat() const
{
	return ((float)getRawBits() / (1 << _fractional_bits));
}

int Fixed::getRawBits() const
{
	return this->_rawbits;
}

// *- Setter Functions -*

void	Fixed::setRawBits( int const raw )
{
	this->_rawbits = raw;
}
