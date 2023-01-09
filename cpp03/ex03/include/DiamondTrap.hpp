/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:53:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/09 22:24:06 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	~DiamondTrap();
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap &);
	DiamondTrap & operator=(const DiamondTrap &);

	void whoAmI();
	void attack(const std::string& target);
private:
	DiamondTrap();
	std::string _name;
};

#endif
