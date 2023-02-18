/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:38:57 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/18 11:52:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice(Ice const &);
	Ice &operator=(Ice const &);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};
