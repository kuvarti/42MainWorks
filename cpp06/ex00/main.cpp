/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:18:28 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/28 23:18:40 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>
#include "ScalarConverter.hpp"

void	printthis(char c)
{
	std::cout << "Char: ";
	if (c < 0)
		std::cout << "Impossible";
	else if (c < 32 || c > 126)
		std::cout << " Non displayable";
	else
		std::cout << "'" << c << "'";
	std::cout << std::endl;
}

void	printthis(int i)
{
	std::cout << "Int: ";
	if (i == -1)
		std::cout << "Impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

void	printthis(float i)
{
	std::cout << "Float: ";
	if (i == -1)
		std::cout << "Impossible";
	else if (std::isnan(i))
		std::cout << "nanf";
	else
	{
		std::cout << i;
		(i - floor(i)) > 0.0f ? std::cout << "f" : std::cout << ".0f";
	}
	std::cout << std::endl;
}

void	printthis(double i)
{
	std::cout << "Double: ";
	if (i == -1)
		std::cout << "Impossible";
	else if (std::isnan(i))
		std::cout << "nan";
	else
	{
		std::cout << i;
		if (!((i - floor(i)) > 0.0f))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("Bad parameters. Use ./Converter <str>\n"));
	std::string str(argv[1]);

	printthis(ScalarConverter::convert<char>(str));
	printthis(ScalarConverter::convert<int>(str));
	printthis(ScalarConverter::convert<float>(str));
	printthis(ScalarConverter::convert<double>(str));
}
