/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showMemory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:19:52 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 15:46:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	PrintZoneName(t_zone *zone)
{
	if (zone->size == TINY)
		ft_printf("TINY : %p\n", zone->ptr);
	else if (zone->size == SMALL)
		ft_printf("SMALL : %p\n", zone->ptr);
	else
		ft_printf("LARGE : %p\n", zone->ptr);
}

void	PrintAllocatedAreas(t_zone *zone)
{
	for (size_t i = 0; i < zone->allocatedZoneCount; i++)
	{
		ft_printf("%p - %p : %u bytes\n", zone->allocatedZones[i].ptr,
			zone->allocatedZones[i].ptr + zone->allocatedZones[i].size,
			zone->allocatedZones[i].size);
	}
}

void	show_alloc_mem() {
	t_zone	*zone;
	size_t	i;

	zone = g_zones;
	if (zone == NULL) {
		ft_printf("No allocated memory\n");
	} else {
		while (zone) {
			PrintZoneName(zone);
			PrintAllocatedAreas(zone);
			zone = zone->next;
			if (zone == g_zones || zone == NULL)
				break ;
		}
	}
}
