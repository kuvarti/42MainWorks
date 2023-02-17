/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:04:53 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/16 14:32:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string name) : _name(name)
{
	std::cout << "Animal String constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(Animal const &a)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = a;
}

Animal &Animal::operator=(Animal const &a)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->_name = a._name;
	this->_type = a._type;
	return *this;
}

std::string Animal::getname() const
{
	return this->_name;
}

void Animal::setname(std::string name)
{
	this->_name = name;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::setType(std::string type)
{
	this->_type = type;
}
