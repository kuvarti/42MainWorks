/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:29:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 09:17:53 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct1("aeryilma");
	ScavTrap ct2("Glavenus");

	ct2.guardGate();
	ct1.setAttackDamage(15);
	ct2.beRepaired(5);
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackValue());
	ct2.guardGate();
}
