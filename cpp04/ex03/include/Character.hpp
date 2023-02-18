/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:12:54 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 15:21:20 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AMateria;

class ICharacter{
public:
	virtual ~ICharacter() {}
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria*) = 0;
	virtual void unequip(int) = 0;
	virtual void use(int idx, ICharacter&) = 0;
};

class Character : public ICharacter{
public:
	Character(std::string const &);
	Character(Character const &);
	Character &operator=(Character const &);
	~Character();

	std::string const & getName() const;
	void equip(AMateria*);
	void unequip(int);
	void use(int idx, ICharacter&);
private:
	std::string const	_name;
	AMateria			*_inventory[4];
}; 
