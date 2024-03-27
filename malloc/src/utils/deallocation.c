/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:20 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 14:23:22 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	Deallocate(t_zone *zone, size_t index)
{
	if (zone->allocatedZoneCount == 1)
	{
		if (!(zone->prev == NULL || zone->next == NULL))
		{
			zone->prev->next = zone->next;
			zone->next->prev = zone->prev;
		}
		zone->ptr = 0;
		zone->size = 0;
		zone->allocatedZoneCount = 0;
		zone->used -= zone->allocatedZones[index].size;
		zone->allocatedZones[index].ptr = NULL;
		zone->allocatedZones[index].size = 0;
		zone = NULL;
		munmap(zone->ptr, zone->size);
	}
	else
	{
		zone->used -= zone->allocatedZones[index].size;
		zone->allocatedZones[index].ptr = NULL;
		zone->allocatedZones[index].size = 0;
		zone->allocatedZoneCount--;
		while (index < zone->allocatedZoneCount - 1)
		{
			zone->allocatedZones[index] = zone->allocatedZones[index + 1];
			index++;
		}
	}
}

#include "libft.h"
void	DeallocateManager(void *ptr) {
	t_FindZoneAndIndex	find;
	t_zone	*zone;
	size_t	i;

	find = FindZoneAndIndex(ptr);
	if (find.zone != NULL)
		Deallocate(find.zone, find.index);
}
