/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:41:40 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/19 22:41:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int j = 0;
		while (argv[++j])
		{
			int i = 0;
			while (argv[j][i])
				std::cout << char(toupper(argv[j][i++]));
		}
	}
	std::cout << std::endl;
	return 0;
}
