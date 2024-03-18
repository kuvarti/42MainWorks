/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preAllocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:12 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/18 17:54:50 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	InitZone(t_zone *zone, size_t size)
{
	zone->size = size;
	zone->used = 0;
	zone->prev = NULL;
	zone->next = NULL;
}

/****
 * AllocateZone
 *
 * Allocates a new zone, initialize it and adds it to the dobulelist of zones.
 * And returns back.
 *
 * Zone size is calculated by the OS's page size.
 *
 * @param gZone: The list of zones to add the new zone to it
 * @param size: The size of the zone to allocate.
 ****/
t_zone	*AllocateZone(t_zone *gZone, size_t size)
{
	t_zone	*zone, *cup;

	if (size < TINY)
		size = TINY;
	else if (size < SMALL)
		size = SMALL;
	zone = (t_zone *)ALLOCATE(sizeof(t_zone));
	zone->ptr = ALLOCATE(size);
	InitZone(zone, size);
	if (gZone == NULL) {
		gZone = zone;
	} else {
		zone->next = gZone->next;
		if (zone->next == NULL)
			zone->next = gZone;
		gZone->next = zone;
		zone->prev = gZone;
		zone->next->prev = zone;
	}
	return (zone);
}

/****
 * FirstCall
 *
 * Runs only once, when there is no zone, creates a new zone and allocates and returns back.
 *
 * @param size: The size of the zone to allocate.
 ****/
void	*FirstCall(size_t size)
{
	t_zone	*zone;
	void	*ret;

	zone = AllocateZone(g_zones, size);
	ret = FindSpaceInZone(zone, size);
	g_zones = zone;
	if (ret != NULL) {
		return (ret);
	}
	return (NULL);
}

/****
 * AllocateManager
 *
 * Manage allocations, if there is no zone, create a new zone and allocate and return back.
 * If there is a zone, check if there is enough space in the zone, if not, create a new zone and allocate and return back.
 * If there is enough space in the zone, allocate and return back.
 *
 * @param neededSize: The size of the space to allocate.
 ****/
void	*AllocateManager(size_t neededSize)
{
	void	*ret;
	t_zone	*tmp, *iter;

	tmp = g_zones;
	if (tmp == NULL)
		return (FirstCall(neededSize));
	if (tmp->next == NULL)
		iter = tmp;
	else
		iter = tmp->next;
	while (1) {
		if (iter == g_zones) {
			if (neededSize + iter->used <= iter->size) {
				ret = FindSpaceInZone(tmp, neededSize);
				if (ret != NULL) {
					return (ret);
				}
			} else {
				tmp = AllocateZone(tmp, neededSize);
				ret = FindSpaceInZone(tmp, neededSize);
				if (ret != NULL) {
					return (ret);
				}
			}
			break;
		}
		if (neededSize + iter->used >= iter->size) {
			iter = iter->next;
			continue;
		}
		else {
			ret = FindSpaceInZone(iter, neededSize);
			if (ret != NULL) {
				continue;
			} else {
				return (ret);
			}
		}
	}
	return (NULL);
}
