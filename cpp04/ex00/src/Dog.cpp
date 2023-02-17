/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:10:31 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/16 14:17:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal(name)
{
	std::cout << "Dog String constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const &a) : Animal(a)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = a;
}

Dog &Dog::operator=(Dog const &a)
{
	std::cout << "Dog assignation operator called" << std::endl;
	this->_name = a._name;
	this->_type = a._type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Hav ulan" << std::endl;
}
