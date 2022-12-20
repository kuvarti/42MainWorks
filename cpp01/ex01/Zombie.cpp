/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 03:25:02 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 04:12:15 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

Zombie::Zombie( std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Nooo im dyingggggg. (" << _name << ")" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;

}

void Zombie::setZombieName(std::string name)
{
	_name = name;
}
