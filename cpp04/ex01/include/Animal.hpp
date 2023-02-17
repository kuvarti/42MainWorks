/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:46:17 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/17 20:47:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"
#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(std::string);
	Animal(Animal const &);
	Animal &operator=(Animal const &);

	virtual void makeSound() const;
	std::string getname() const;
	void setname(std::string);

	std::string getType() const;
	void setType(std::string);

protected:
	std::string _type;
private:
	std::string _name;
};
