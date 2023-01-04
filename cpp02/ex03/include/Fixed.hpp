/* ************************************************************************** */
/*                                                                             */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:47:05 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/28 01:14:33 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
public:
	//* Constructors
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &);
	~Fixed();

	//* Assignment Operator
	Fixed & operator=(const Fixed &);

	//* Bool Operators
	bool	operator>(const Fixed &) const;
	bool	operator<(const Fixed &) const;
	bool	operator>=(const Fixed &) const;
	bool	operator<=(const Fixed &) const;
	bool	operator==(const Fixed &) const;
	bool	operator!=(const Fixed &) const;

	//* Arithmetic Operators
	Fixed	operator+(const Fixed &) const;
	Fixed	operator-(const Fixed &) const;
	Fixed	operator*(const Fixed &) const;
	Fixed	operator/(const Fixed &) const;

	//* Increment & Decrement Operators
	// *- prefix -*
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	// *- postfix -*
	Fixed	operator++(int);
	Fixed	operator--(int);

	//* Min & Max
	static Fixed		&min(Fixed &, Fixed &);
	static const Fixed	&min(const Fixed &, const Fixed &);
	static Fixed		&max(Fixed &, Fixed &);
	static const Fixed	&max(const Fixed &, const Fixed &);

	//* Getters
	int		getRawBits( void ) const;

	//* Setters
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_rawbits;
	static const int	_fractional_bits = 8;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);

#endif
