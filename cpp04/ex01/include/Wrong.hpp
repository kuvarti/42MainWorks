/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:50:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/16 15:18:59 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &a);
		WrongAnimal &operator=(WrongAnimal const &a);
		~WrongAnimal();

		void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(WrongCat const &a);
		WrongCat &operator=(WrongCat const &a);
		~WrongCat();

		void makeSound() const;
};
