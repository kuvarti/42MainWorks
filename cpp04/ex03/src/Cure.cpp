/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:19:55 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 14:21:12 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {

}

Cure::Cure(Cure const &obj) : AMateria(obj) {
	*this = obj;
}

Cure &Cure::operator=(Cure const &obj) {
	AMateria::operator=(obj);
	return *this;
}

Cure::~Cure() {

}

Cure::AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
