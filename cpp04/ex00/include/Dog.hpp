/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:59:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/16 14:16:52 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal{
public:
	Dog();
	~Dog();
	Dog(std::string);
	Dog(Dog const &);
	Dog &operator=(Dog const &);
	void makeSound() const;
private:
	std::string _name;
};
