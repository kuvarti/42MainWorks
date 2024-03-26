/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:38:56 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:31:45 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
// # include <stdlib.h>

// Mandatory functions
void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();

# define TINY (getpagesize() * 4)
# define SMALL (getpagesize() * 32)

typedef struct s_allocatedZone
{
	size_t	size;
	void	*ptr;
}	t_allocatedZone;

typedef struct s_zone
{
	size_t	size;
	size_t	used;
	void	*ptr;
	t_allocatedZone	allocatedZones[100];
	size_t	allocatedZoneCount;

	struct s_zone	*next;
	struct s_zone	*prev;
}	t_zone;


// Utils
typedef struct FindZoneAndIndex
{
	t_zone	*zone;
	size_t	index;
	t_allocatedZone	*allocatedZone;
}	t_FindZoneAndIndex;

extern t_zone	*g_zones;

# define ALLOCATE(SIZE) mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)

void	*AllocateManager(size_t neededSize);
void	*FindSpaceInZone(t_zone *zone, size_t size);
void	DeallocateManager(void *ptr);
void	*ReAllocateManager(void *ptr, size_t size);

void	AppendZoneFront(t_zone *Node, t_zone *NewZone);
void	AppendZoneBack(t_zone *Node, t_zone *NewZone);

t_FindZoneAndIndex	FindZoneAndIndex(void *ptr);

#endif
