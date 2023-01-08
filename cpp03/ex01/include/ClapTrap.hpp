/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:13:35 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/08 01:45:46 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap{
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(std::string);
	ClapTrap (const ClapTrap &);
	ClapTrap & operator=(const ClapTrap &);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void			setAttackDamage(unsigned int);

	std::string		getName() const;
	unsigned int	getAttackValue() const;
private:
	std::string	_name;
	int	_hitpoint;
	int	_energypoint;
	int	_attackdamage;
};

#endif
