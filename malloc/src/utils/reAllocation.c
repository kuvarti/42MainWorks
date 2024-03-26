/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reAllocation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:28:46 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:27:36 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include "libft.h"

void	*ReAllocateManager(void *ptr, size_t size)
{
	t_FindZoneAndIndex	find;

	write(1, "realloc\n", 8);
	find = FindZoneAndIndex(ptr);
	if (find.zone == NULL)
		return (NULL);
	if (find.allocatedZone->ptr + size < find.zone->allocatedZones[find.index + 1].ptr) {
		find.allocatedZone->size = size;
		return (find.allocatedZone->ptr);
	}
	else
	{
		void *ret;
		ret = AllocateManager(size);
		ft_memcpy(ret, ptr, find.allocatedZone->size);
		DeallocateManager(find.zone);
		return (ret);
	}
}
