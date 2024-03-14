/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:38:56 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 13:20:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <sys/mman.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# define NULLPTR ((void *)NULL)

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

typedef enum e_zoneSize
{
	TINY = 128,
	SMALL = 1024,
	LARGE = 1024 * 1024
}	t_zoneSize;


#endif
