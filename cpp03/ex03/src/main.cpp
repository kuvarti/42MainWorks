/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:29:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 16:44:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ct1("aeryilma");
	FragTrap ct2("Glavenus");

	ct1.setAttackDamage(15);
	ct2.beRepaired(5);
	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackValue());
	ct2.highFivesGuys();
}
