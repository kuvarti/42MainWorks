/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:51:39 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/23 00:14:50 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*Intern::makeForm(std::string form, std::string target)
{
	size_t i;
	std::string	forms[3] = {"Shrubbery" , "Presidential", "Robotomy"};

	for (i = 0; i < 3; i++)
	{
		if (form == forms[i])
			break ;
	}
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << "Shrubbery" << std::endl;
		return (new ShrubberyCreationForm(target));
		break;
	case 1:
		std::cout << "Intern creates " << "Presidential" << std::endl;
		return (new PresidentialPardonForm(target));
		break;
	case 2:
		std::cout << "Intern creates " << "Robotomy" << std::endl;
		return (new RobotomyRequestForm(target));
		break;
	default:
		std::cout << "Intern cannot find form." << std::endl;
		return (nullptr);
		break;
	}
}
