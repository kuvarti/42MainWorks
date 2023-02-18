/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:19:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 14:19:40 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(Cure const &);
	Cure &operator=(Cure const &);
	~Cure();

	AMateria* clone() const;
	void use(ICharacter& target);
};
