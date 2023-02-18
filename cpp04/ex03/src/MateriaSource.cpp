/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:47:00 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 16:07:10 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		_learned[i] = nullptr;
	}
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	*this = m;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &m)
{
	if (this != &m)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (_learned[i])
				delete _learned[i];
			_learned[i] = m._learned[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_learned[i])
			delete _learned[i];
	}
}

void	MateriaSource::learnMateria(AMateria *a)
{
	int		check = 0;
	size_t	i;
	for (i = 0; i < 4; i++)
	{
		if (!_learned[i])
		{
			check = 1;
			break ;
		}
	}
	if (!check)
	{
		std::cout << "Memory is full!" << std::endl;
		return ;
	}
	_learned[i] = a;
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	size_t i;
	for (i = 0; i < 4; i++)
	{
		if (_learned[i]->getType() == type)
			break ;
	}
	if (i == 4)
	{
		std::cout << type << " is unknown." << std::endl;
		return nullptr;
	}
	return (_learned[i]->clone());
}
