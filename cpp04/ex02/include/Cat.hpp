/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:21:01 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/17 21:30:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal{
public:
	Cat();
	~Cat();
	Cat(std::string);
	Cat(Cat const &);
	Cat &operator=(Cat const &);
	void makeSound() const;

	Brain		*_brain;
private:
	std::string	_name;
};
