/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:58:20 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 13:31:31 by aeryilma         ###   ########.fr       */
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
		munmap(zone->ptr, zone->size);
	}
	else
	{
		zone->used -= zone->allocatedZones[index].size;
		zone->allocatedZones[index].ptr = NULL;
		zone->allocatedZones[index].size = 0;
		while (index < zone->allocatedZoneCount - 1)
		{
			zone->allocatedZones[index] = zone->allocatedZones[index + 1];
			index++;
		}
	}
}

void	DeallocateManager(void *ptr) {
	t_zone	*zone;
	size_t	i;

	if (g_zones == NULL)
		return ;
	zone = g_zones;
	while (zone)
	{
		i = 0;
		while (i < zone->allocatedZoneCount)
		{
			if (zone->allocatedZones[i].ptr == ptr)
				Deallocate(zone, i);
			i++;
		}
		zone = zone->next;
		if (zone == g_zones || zone == NULL)
			break ;
	}
}
