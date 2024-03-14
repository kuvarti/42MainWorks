/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preAllocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:12 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 16:27:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	InitZone(t_zone *zone, size_t size)
{
	zone->size = size;
	zone->used = 0;
	zone->ptr = NULLPTR;
	zone->allocatedZones = NULLPTR;
	zone->next = NULLPTR;
	zone->prev = NULLPTR;
}

t_zone	*AllocateZone(size_t size)
{
	t_zone	*zone;
	if (size < TINY)
		size = TINY;
	else if (size < SMALL)
		size = SMALL;
	else if (size < LARGE)
		size = LARGE;
	zone = ALLOCATE(size);
	InitZone(zone, size);
	return (zone);
}

//TODO: Manage zones, removes unnessery ones, creates new ones and handles the links
void	AllocateManager(size_t neededSize)
{
	t_zone	*tmp;
	t_zone	*iter;

	tmp = g_zones;
	if (tmp->next == NULLPTR)
		iter = tmp;
	else
		iter = tmp->next;
	while (1) {
		if (iter == g_zones) {
			if (neededSize + iter->used >= iter->size)
				tmp = AllocateZone(neededSize);
			break;
		}
		if (neededSize + iter->used >= iter->size) {
			iter = iter->next;
			continue;
		}
		else {

		}
	}
}
