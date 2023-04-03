/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:31:21 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/29 21:13:07 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int>	vec;
	std::vector<int>::iterator	it;

	for (size_t i = 0; i < 10; i++)
		vec.push_back(i * 2);
	it = easyfind(vec, 4);
	std::cout << "iterator for 4: " << *it << std::endl;

	try { it = easyfind(vec, 3); }
	catch (const std::exception &e) { std::cerr << e.what() << '\n'; }
}
