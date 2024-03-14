/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findSpaceInZone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:31 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 17:26:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	AppendAllocatedZone(t_allocatedZone *zone, t_allocatedZone *newZone) {
	t_allocatedZone	*tmp, *cup;

	tmp = zone;
	cup = tmp;
	if (tmp->ptr > newZone->ptr)
	{
		newZone->next = tmp;
		zone = newZone;
		return;
	}
	while (tmp != NULLPTR) {
		if (tmp->next == NULLPTR) {
			tmp->next = newZone;
			break;
		}
		if (tmp->ptr > newZone->ptr) {
			cup->next = newZone;
			newZone->next = tmp;
			break;
		}
		cup = tmp;
		tmp = cup->next;
	}
}

t_allocatedZone	*GetBlockInZone(void *start, size_t size) {
	t_allocatedZone	*tmp;

	tmp = (t_allocatedZone *)mmap(NULL, sizeof(t_allocatedZone), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	tmp->size = size;
	tmp->ptr = start;
	tmp->next = NULLPTR;
	return (tmp);
}

void	*FindSpaceInZone(t_zone *zone, size_t size) {
	void *zoneEnd, *spaceStart;
	t_allocatedZone	*tmp;

	zoneEnd = zone->ptr + zone->size;
	tmp = zone->allocatedZones;
	if (tmp == NULLPTR) {
		AppendAllocatedZone(zone->allocatedZones, GetBlockInZone(zone->ptr, size));
		return (zone->ptr);
	}


	//YANLIS!!
	while (tmp != NULLPTR) {
		spaceStart = tmp->ptr + tmp->size + 1;
		if (tmp->next == NULL) {
			if (spaceStart <= zoneEnd)
				return NULLPTR;
			else
				AppendAllocatedZone(zone->allocatedZones, GetBlockInZone(spaceStart, size));
		}
	}
}
