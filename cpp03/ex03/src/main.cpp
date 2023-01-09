/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:29:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/09 22:22:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap ct1("aeryilma");
	FragTrap ct2("Glavenus");
	DiamondTrap dt("Kuvarti");

	dt.attack(ct2.getName());
}
