/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:46:17 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/16 14:37:59 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal
{
public:
	Animal();
	~Animal();
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
