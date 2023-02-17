/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:54:52 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/17 18:18:07 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Wrong.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* arr[4];
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl << "Getting types from animal pointer(s)" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "Wrong : " << wrong->getType() << " " << std::endl;
	std::cout << std::endl << "Getting Sounds from animal pointer(s)" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "Wrong : "; wrong->makeSound();

	arr[0] = meta;
	arr[1] = j;
	arr[2] = i;
	std::cout << std::endl << "Getting Infos from animal pointer array" << std::endl;
	for (int f = 0; f < 3; f++)
	{
		std::cout << arr[f]->getType() << " ";
		arr[f]->makeSound();
	}

	return 0;
}
