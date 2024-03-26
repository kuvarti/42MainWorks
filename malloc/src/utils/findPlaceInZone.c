/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPlaceInZone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:10:47 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 15:37:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_FindZoneAndIndex	FindZoneAndIndex(void *ptr)
{
	t_FindZoneAndIndex	find;
	t_zone	*zone;
	size_t	i;

	find.zone = NULL;
	find.index = 0;
	if (g_zones == NULL)
		return find;
	zone = g_zones;
	while (zone)
	{
		i = 0;
		while (i < zone->allocatedZoneCount)
		{
			if (zone->allocatedZones[i].ptr == ptr){
				find.zone = zone;
				find.index = i;
				find.allocatedZone = &zone->allocatedZones[i];
				return (find);
			}
			i++;
		}
		zone = zone->next;
		if (zone == g_zones || zone == NULL)
			break ;
	}
	return (find);
}
