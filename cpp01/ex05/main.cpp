/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 21:27:14 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/21 21:52:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	Harl hrl;
	if (argc == 1)
	{
		std::string inp;
		std::cout << "Please enter a status : ";
		std::cin >> inp;
		hrl.complain(inp);
	}
	else
	{
		hrl.complain(argv[1]);
	}
}
