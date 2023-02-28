/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:04:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/28 23:16:45 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <type_traits>
#include <iostream>
#include <math.h>

template char ScalarConverter::convert(const std::string&);
template int ScalarConverter::convert(const std::string&);
template float ScalarConverter::convert(const std::string&);
template double ScalarConverter::convert(const std::string&);

template<typename T>T ScalarConverter::convert(const std::string &str)
{
	T result;

	if (std::is_same<T, char>::value)
	{
		try { result = std::stoi(str); }
		catch(const std::exception& e) { return (-1); }
		return (result);
	}
	if (std::is_same<T, int>::value)
	{
		try { result = std::stoi(str); }
		catch(const std::exception& e) { return (-1); }
		return (result);
	}
	if (std::is_same<T, float>::value)
	{
		float r;
		try { r = std::stof(str); }
		catch(const std::exception& e) { return (-1); }
		return (r);
	}
	if (std::is_same<T, double>::value)
	{
		double r;
		try { r = std::stod(str); }
		catch(const std::exception& e) { return (-1); }
		return (r);
	}
	result = -1;
	return result;
}

