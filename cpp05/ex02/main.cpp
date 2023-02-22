/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:07:29 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/22 23:32:22 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialForm.hpp"
#include "ShrubberyForm.hpp"
#include "RobotomyForm.hpp"
#include <time.h>

void	sartel(Bureaucrat &br, AForm &af)
{
	std::cout << br.getName() << " and " << af.getname() << "." << std::endl;
	try
	{
		std::cout << "Signing " << br.getName() << "." << std::endl;
		br.signForm(af);
		std::cout << "Executing " << br.getName() << "." << std::endl;
		br.executeForm(af);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	Bureaucrat	*buro = new Bureaucrat("Malenia", 1);
	Bureaucrat	*buro1 = new Bureaucrat("Godrick", 50);
	Bureaucrat	*buro2 = new Bureaucrat("Margit", 146);

	AForm	*shrubbery = new ShrubberyCreationForm("cali");
	AForm	*robotomy = new RobotomyRequestForm("Robot");
	AForm	*president = new PresidentialPardonForm("Başkanlik");

	sartel(*buro, *shrubbery);
	sartel(*buro, *robotomy);
	sartel(*buro, *president);

	sartel(*buro1, *shrubbery);
	sartel(*buro1, *robotomy);
	sartel(*buro1, *president);

	sartel(*buro2, *shrubbery);
	sartel(*buro2, *robotomy);
	sartel(*buro2, *president);
}
