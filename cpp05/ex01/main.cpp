/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:07:29 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 16:41:59 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <time.h>

int	main(void)
{
	Bureaucrat	*buro = new Bureaucrat("Malenia", 50);
	Form		*rapor = new Form("İşgörmez", 90, 100);
	Form		*rapor1 = new Form("Kaza", 10, 20);

	std::cout << buro->getName() << " and " << rapor->getname() << "." << std::endl;
	try
	{
		std::cout << "Signing " << rapor->getname() << "." << std::endl;
		buro->signForm(*rapor);
		std::cout << "Resigning " << rapor->getname() << "." << std::endl;
		buro->signForm(*rapor);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << buro->getName() << " and " << rapor1->getname() << "." << std::endl;
	try
	{
		std::cout << "Signing " << rapor1->getname() << "." << std::endl;
		buro->signForm(*rapor1);
		std::cout << "Resigning " << rapor1->getname() << "." << std::endl;
		buro->signForm(*rapor1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	delete buro; delete rapor; delete rapor1;
}
