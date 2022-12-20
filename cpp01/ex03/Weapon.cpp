/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:21:07 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 18:27:15 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::Weapon()
{
	// DOIN NOTHING
}

Weapon::~Weapon()
{

}

std::string Weapon::getType()
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
