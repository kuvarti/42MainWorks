/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:14 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/17 20:52:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(std::string name) : Animal(name)
{
	std::cout << "Cat String constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &a) : Animal(a)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = a;
}

Cat &Cat::operator=(Cat const &a)
{
	std::cout << "Cat assignation operator called" << std::endl;
	this->_name = a._name;
	this->_type = a._type;
	this->_brain = a._brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miyav ayol" << std::endl;
}
