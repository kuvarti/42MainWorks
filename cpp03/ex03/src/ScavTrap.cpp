/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 08:07:37 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 09:19:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hitpoint = 100;
	this->_energypoint = 50;
	this->_attackdamage = 20;
	this->_keeping_gate = false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap is destroyed" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitpoint = 100;
	this->_energypoint = 50;
	this->_attackdamage = 20;
	this->_keeping_gate = false;
	std::cout << "ScavTrap String Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c): ClapTrap(c)
{
	this->_hitpoint = c._hitpoint;
	this->_energypoint = c._energypoint;
	this->_attackdamage = c._attackdamage;
	this->_keeping_gate = c._keeping_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &c)
{
	this->_name = c._name;
	this->_hitpoint = c._hitpoint;
	this->_energypoint = c._energypoint;
	this->_attackdamage = c._attackdamage;
	this->_keeping_gate = c._keeping_gate;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (_energypoint > 0)
		std::cout << _name << " attacks to " << target << " and deal " << _attackdamage << " damage." << std::endl;
	_energypoint--;
}

void	ScavTrap::guardGate()
{
	_keeping_gate ^= true;
	if (_keeping_gate)
		std::cout << _name << " is keeping the gate." << std::endl;
	else
		std::cout << _name << " is not keeping the gate." << std::endl;
}
