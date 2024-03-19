/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preAllocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:49:12 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 15:35:37 by aeryilma         ###   ########.fr       */
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

t_zone	*AppendAndSortZone(t_zone *zone)
{
	t_zone	*tmp;

	tmp = g_zones;
	if (tmp == NULL){
		g_zones = zone;
		return (zone);
	}
	while (1) {
		if (tmp->size > zone->size) {
			AppendZoneFront(tmp, zone);
			return (zone);
		}
		tmp = tmp->next;
		if (tmp == g_zones || tmp == NULL) {
			AppendZoneBack(g_zones, zone);
			return (zone);
		}
	}
}

t_zone	*AllocateZone(size_t size)
{
	t_zone	*zone, *cup, *gZone;

	if (size < TINY)
		size = TINY;
	else if (size < SMALL)
		size = SMALL;
	zone = (t_zone *)ALLOCATE(sizeof(t_zone));
	zone->ptr = ALLOCATE(size);
	InitZone(zone, size);
	return (AppendAndSortZone(zone));
}

void	*FirstCall(size_t size)
{
	t_zone	*zone;
	void	*ret;

	zone = AllocateZone(size);
	ret = FindSpaceInZone(zone, size);
	if (ret != NULL) {
		return (ret);
	}
	return (NULL);
}

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
				tmp = AllocateZone(neededSize);
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
