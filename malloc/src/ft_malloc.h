/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:38:56 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 16:27:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define NULLPTR ((void *)NULL)

// Mandatory functions
void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

typedef enum e_zoneSize
{
	TINY = 128,
	SMALL = 1024,
	LARGE = 1024 * 1024
}	t_zoneSize;

typedef struct s_allocatedZone
{
	size_t	size;
	void	*ptr;//? burada garip seyler olacak
	struct s_allocatedZone	*next;
}	t_allocatedZone;

typedef struct s_zone
{
	size_t	size;
	size_t	used;
	void	*ptr;
	t_allocatedZone	*allocatedZones;

	struct s_zone	*next;
	struct s_zone	*prev;
}	t_zone;

extern t_zone	*g_zones;


// Utils
# define ALLOCATE(SIZE) (t_zone *)mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)

t_zone	*AllocateZone(size_t size);

#endif
