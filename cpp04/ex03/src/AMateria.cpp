/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:17:01 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 15:01:06 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {

}

AMateria::AMateria(AMateria const &obj) {
	*this = obj;
}

AMateria &AMateria::operator=(AMateria const &obj) {
	_type = obj._type;
	return *this;
}

AMateria::~AMateria() {

}

std::string const &AMateria::getType() const {
	return _type;
}

void	AMateria::use(ICharacter&  target){
	target = target;
}
