/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preAllocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:12 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/15 17:40:41 by aeryilma         ###   ########.fr       */
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

t_zone	*AllocateZone(t_zone *gZone, size_t size)
{
	t_zone	*zone, *cup;

	if (size < TINY)
		size = TINY;
	else if (size < SMALL)
		size = SMALL;
	else if (size < LARGE)
		size = LARGE;
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

//TODO: Manage zones, removes unnessery ones, creates new ones and handles the links
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
