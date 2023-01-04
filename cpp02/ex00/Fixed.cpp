/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 23:47:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/04 03:17:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

fixed::fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

fixed::fixed (const fixed &f) : _rawbits(f.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

fixed::~fixed()
{
	std::cout << "Destructor called" << std::endl;
}

fixed::fixed operator = (const fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_rawbits = f.getRawBits();
}

int fixed::getRawBits()
{
	return this->_rawbits;
}

void	fixed::setRawBits( int const raw )
{
	this->_rawbits = raw;
}
