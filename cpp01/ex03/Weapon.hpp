/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:19:13 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/20 18:26:23 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{
public:
	Weapon();
	Weapon(std::string);
	~Weapon();
	std::string getType();
	void setType(std::string);
private:
	std::string _type;
};

#endif
