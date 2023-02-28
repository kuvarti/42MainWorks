/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:23:10 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 01:02:21 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>

typedef struct randomdata
{
	int		rnd;
}	Data;


class Serializer{
public:
	static uintptr_t serialize(Data *);
	static Data* deserialize(uintptr_t);
};
