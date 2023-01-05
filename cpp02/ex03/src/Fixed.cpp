/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:47:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/05 04:59:54 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// *-*-*-*-*- Constructors -*-*-*-*-*
// Default Constructor
Fixed::Fixed() : _rawbits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &f) : _rawbits(f.getRawBits())
{
	// std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Fixed & Fixed::operator=(const Fixed &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		_rawbits = f.getRawBits();
	return *this;
}

// Integer Constructor
Fixed::Fixed(const int raw) : _rawbits(raw << _fractional_bits)
{
	// std::cout << "Int constructor called" << std::endl;
}

// Float Constructor
Fixed::Fixed(const float raw) : _rawbits(roundf(raw * (1 << _fractional_bits)))
{
	// std::cout<< "Float constructor called" << std::endl;
}

// *-*-*-*-*- Member Functions -*-*-*-*-*

// *- Bool Operators -*

bool	Fixed::operator>(const Fixed &f) const
{
	return (this->_rawbits > f.getRawBits());
}

bool	Fixed::operator<(const Fixed &f) const
{
	return (this->_rawbits < f.getRawBits());
}

bool	Fixed::operator>=(const Fixed &f) const
{
	return (this->_rawbits >= f.getRawBits());
}

bool	Fixed::operator<=(const Fixed &f) const
{
	return (this->_rawbits <= f.getRawBits());
}

bool	Fixed::operator==(const Fixed &f) const
{
	return (this->_rawbits == f.getRawBits());
}

bool	Fixed::operator!=(const Fixed &f) const
{
	return (this->_rawbits != f.getRawBits());
}

// *- Arithmetic Operators -*

Fixed	Fixed::operator+(const Fixed &f) const
{
	return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	return (Fixed(this->toFloat() / f.toFloat()));
}

// *- Increment Operators -*

Fixed	&Fixed::operator++()
{
	this->_rawbits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	&Fixed::operator--()
{
	this->_rawbits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// *- Min and Max -*

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
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

// *-*-*-*-*- Overload Operators -*-*-*-*-*

std::ostream & operator<<(std::ostream &o, const Fixed &f)
{
	o << f.toFloat();
	return o;
}
