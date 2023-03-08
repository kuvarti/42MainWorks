/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:54:52 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/06 22:58:25 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* zoo[4];
	//const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl << "Getting types from animal pointer(s)" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl << "Getting Sounds from animal pointer(s)" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();

	std::cout << std::endl << "Deleting Animal pointer(s)" << std::endl;
	delete j;
	delete i;
	//delete meta;

	std::cout << std::endl << "-*  Creating Zoo  *-" << std::endl;
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();

	std::cout << std::endl << "Getting Infos from animal pointer array. And Deletes" << std::endl;
	for (int f = 0; f < 4; f++)
	{
		std::cout << "------------" << std::endl;
		std::cout << "Type: " << zoo[f]->getType() << " Sound: "; zoo[f]->makeSound();
		delete zoo[f];
	}
	std::cout << "------------" << std::endl << "Copy Test" << std::endl;

	Dog *dog = new Dog();
	dog->_brain->setIdea(0, "Am i a dog?");
	Dog *copy = new Dog(*dog);
	std::cout << "Dog's idea: " << dog->_brain->getIdea(0) << std::endl;
	std::cout << "Copy's idea: " << copy->_brain->getIdea(0) << std::endl;
	delete dog;
}
