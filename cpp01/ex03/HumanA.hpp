/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:48:26 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 22:48:32 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include "string"

class HumanA{
public:
	HumanA(std::string, Weapon&);
	void attack();
private:
	std::string _name;
	Weapon &_weapon;
};

#endif
