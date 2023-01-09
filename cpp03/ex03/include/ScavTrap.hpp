/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 02:13:06 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/09 21:57:21 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap &);
	ScavTrap & operator=(const ScavTrap &);

	void attack(const std::string& target);

	void	guardGate();
private:
	bool	_keeping_gate;
};

#endif
