/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:48:11 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/18 18:26:28 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void free(void *ptr)
{
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
			{
			}
			i++;
		}
		if (zone->next == NULL)
			break ;
		zone = zone->next;
		if (zone == g_zones)
			break ;
	}
}
