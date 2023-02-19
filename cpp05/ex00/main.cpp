/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:07:29 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/19 16:08:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <time.h>

int	main(void)
{
	Bureaucrat	a("Margit", 50);
	Bureaucrat	*b;
	try
	{
		b = new Bureaucrat("Godrick", 120);
		b->incrementGrade(a.getGrade());
		a.setGrade(200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::cout << a;
		std::cout << *b;
	}

}
