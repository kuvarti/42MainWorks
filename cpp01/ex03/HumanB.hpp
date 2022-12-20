/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:33:03 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 22:45:09 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB{
public:
	HumanB(std::string);
	~HumanB() {};
	void attack();
	void setWeapon(Weapon&);
private:
	Weapon		*_weapon;
	std::string	_name;
};

#endif
