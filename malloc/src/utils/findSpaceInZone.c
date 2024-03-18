/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findSpaceInZone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:31 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/18 17:58:07 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

/****
 * AppendAllocatedZone
 *
 * Adds the new allocated zone to the zone's allocated zones.
 * The oparasion will have to order the allocated zones in the zone.
 *
 * @param zone: The zone to add the new allocated zone to it.
 * @param newZone: The new allocated zone to add to the zone.
 ****/
void AppendAllocatedZone(t_zone *zone, t_allocatedZone newZone) {
	size_t allocatedZoneCount = zone->allocatedZoneCount;
	t_allocatedZone *allocatedZones = zone->allocatedZones;

	if (allocatedZoneCount >= 100) {
		return;
	}
	size_t insertIndex = 0;
	while (insertIndex < allocatedZoneCount && ((intptr_t)allocatedZones[insertIndex].ptr < (intptr_t)newZone.ptr)) {
		insertIndex++;
	}
	for (size_t i = allocatedZoneCount; i > insertIndex; i--) {
		allocatedZones[i] = allocatedZones[i - 1];
	}
	allocatedZones[insertIndex] = newZone;
	zone->used += newZone.size;
	zone->allocatedZoneCount++;
}


/****
 * GetBlockInZone
 *
 * Returns a allocated zone with the given start and size.
 *
 * @param start: The start of the allocated zone.
 * @param size: The size of the allocated zone.
 ****/
t_allocatedZone	GetBlockInZone(void *start, size_t size) {
	t_allocatedZone	tmp;

	tmp.size = size;
	tmp.ptr = start;
	return (tmp);
}

/****
 * FindSpaceInZone
 *
 * Tries find a space in the zone,
 * If it can't find, returns NULL.
 * If it finds, appends the allocated zone to the zone and returns the start of the space.
 *
 * This function have to order allocated spaces in the zone.
 *
 * @param zone: The zone to find space in.
 * @param size: The size of the space to find.
 ****/
void	*FindSpaceInZone(t_zone *zone, size_t size) {
	void *zoneEnd, *spaceStart;
	t_allocatedZone	*tmp, ret;

	zoneEnd = zone->ptr + zone->size;
	tmp = zone->allocatedZones;
	if (zone->allocatedZoneCount == 0) {
		AppendAllocatedZone(zone, GetBlockInZone(zone->ptr, size));
		return (zone->ptr);
	}
	for (size_t i = 0; i < zone->allocatedZoneCount; i++) {
		spaceStart = tmp[i].ptr + tmp[i].size + 1;
		if (spaceStart >= zoneEnd) {
			return NULL;
		}
		if (tmp[i + 1].size != 0) {
			if (spaceStart + size <= tmp[i + 1].ptr) {
				ret = GetBlockInZone(spaceStart, size);
				AppendAllocatedZone(zone, ret);
				return (spaceStart);
			}
		}
		else if (spaceStart + size <= zoneEnd) {
			ret = GetBlockInZone(spaceStart, size);
			AppendAllocatedZone(zone, ret);
			return (spaceStart);
		}
	}
	return NULL;
}
