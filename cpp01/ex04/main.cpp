/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:59:12 by aeryilma          #+#    #+#             */
/*   Updated: 2022/12/21 00:39:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myStream.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return 0;

	myStream myst(argv[1]);
	myst.replace(argv[2], argv[3]);
}
