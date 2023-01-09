/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:33:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/09 22:09:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitpoint = 100;
	this->_energypoint = 30;
	this->_attackdamage = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap id destroyed" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
		this->_hitpoint = 100;
	this->_energypoint = 30;
	this->_attackdamage = 30;
	std::cout << "FragTrap String Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f)
{
	this->_hitpoint = f._hitpoint;
	this->_energypoint = f._energypoint;
	this->_attackdamage = f._attackdamage;
	std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap &f)
{
	this->_name = f._name;
	this->_hitpoint = f._hitpoint;
	this->_energypoint = f._energypoint;
	this->_attackdamage = f._attackdamage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << _name << " wants to highFive to you." << std::endl;
}
