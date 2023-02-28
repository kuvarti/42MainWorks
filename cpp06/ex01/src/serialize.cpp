/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:34:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/03/01 01:32:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"

uintptr_t Serializer::serialize(Data *d)
{
	uintptr_t	ret;

	ret = d->rnd;
	return (ret);
}

Data* Serializer::deserialize(uintptr_t u)
{
	Data	*ret = new Data;

	ret->rnd = u;
	return (ret);
}
