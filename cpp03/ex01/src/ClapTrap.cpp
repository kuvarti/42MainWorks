/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:33:40 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 09:12:37 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// *-*-*-*-*- Constructors -*-*-*-*-*
ClapTrap::ClapTrap()
	: _name(""), _hitpoint(10), _energypoint(10), _attackdamage(0)
{
	_name = "ClapTrap";
	std::cout << _name << " is created with " << "[Default Constructor]" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << "is closed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	_name = c._name;
	_hitpoint = c._hitpoint;
	_energypoint = c._energypoint;
	_attackdamage = c._attackdamage;
	std::cout << _name << " is created with " << "[Copy Constructor]" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &c)
{
	_name = c._name;
	_hitpoint = c._hitpoint;
	_energypoint = c._energypoint;
	_attackdamage = c._attackdamage;
	return (*this);
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitpoint(10), _energypoint(10), _attackdamage(0)
{
	std::cout << _name << " is created with " << "[String Constructor]" << std::endl;
}

// *-*-*-*-*- Public members -*-*-*-*-*
void	ClapTrap::attack(const std::string& target)
{
	if (_energypoint > 0)
		std::cout << _name << " attacks to " << target << " and deal " << _attackdamage << " damage." << std::endl;
	_energypoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoint -= amount;
	if (_hitpoint <= 0)
	{
		std::cout << _name << " takes a lot damage it cant handle it. its energy set to 0." << std::endl;
		_energypoint = 0;
	}
	else
		std::cout << _name << " takes " << amount << " damage, remain hitpoints: " << _hitpoint << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitpoint <= 0)
	{
		std::cout << _name << " cannot be repaired. b'cause it hasn't any enerypoint." << std::endl;
		return ;
	}
	_hitpoint += amount;
	_energypoint--;
	std::cout << _name << "is repaired. Now its Hitpoint: " << _hitpoint << std::endl;
}

std::string	ClapTrap::getName() const
{
	return _name;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackdamage = amount;
	std::cout << _name << "'s damage has been set " << amount << std::endl;
}

unsigned int	ClapTrap::getAttackValue() const
{
	if (_attackdamage <= 0)
		return 0;
	return _attackdamage;
}
