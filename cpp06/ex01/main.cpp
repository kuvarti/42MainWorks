/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:43:32 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 01:20:45 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>

int main()
{
	Data*	selam = new Data;
	Data	*temp;

	selam->rnd = 32;
	uintptr_t data = Serializer::serialize(selam);
	temp = Serializer::deserialize(data);

	std::cout << temp->rnd << std::endl;
	delete selam;
}
