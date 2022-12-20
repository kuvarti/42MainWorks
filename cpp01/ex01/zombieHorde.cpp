/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:03:32 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 04:14:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *ret = new Zombie[N];
	for (int i = 0; i < 5; i++)
	{
		ret[i].setZombieName(name);
	}
	return ret;
}
