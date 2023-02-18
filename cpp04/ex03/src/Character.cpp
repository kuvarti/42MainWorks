/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:29:55 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 15:26:51 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(Character const &c)
{
	*this = c;
}

Character &Character::operator=(Character const &c)
{
	if (this != &c)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			_inventory[i] = c._inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	size_t	i;
	int		check = 0;
	for (i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			check = 1;
			break;
		}
	}
	if (!check)
	{
		std::cout << "There is no space for Material on inventory" << std::endl;
		return ;
	}
	_inventory[i] = m;
}

void	Character::unequip(int i){
	if (_inventory[i])
		_inventory[i] = nullptr;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx])
	{
		std::cout << "There is no item in " << idx << ". slot." << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}
