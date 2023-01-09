/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:35:36 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/09 22:26:23 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
	this->_name = "<namelessDiamond>";
	this->_hitpoint = FragTrap::_hitpoint;
	this->_energypoint = ScavTrap::_energypoint;
	this->_attackdamage = FragTrap::_attackdamage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << _name << " is destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	this->_hitpoint = FragTrap::_hitpoint;
	this->_energypoint = ScavTrap::_energypoint;
	this->_attackdamage = FragTrap::_attackdamage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &p)
{
	this->_name = p._name;
	this->_hitpoint = p._hitpoint;
	this->_energypoint = p._energypoint;
	this->_attackdamage = p._attackdamage;
	std::cout << _name << " is created." << std::endl;
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &p)
{
	this->_name = p._name;
	this->_hitpoint = p._hitpoint;
	this->_energypoint = p._energypoint;
	this->_attackdamage = p._attackdamage;
	std::cout << _name << " is created." << std::endl;
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrapname is : " << ClapTrap::_name << ", DiamondTrap name is : " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	std::cout << "Called by Diamond:";
	ScavTrap::attack(target);
};
