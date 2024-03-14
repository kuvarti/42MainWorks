/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:03 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 16:23:30 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>

t_zone	*g_zones = NULL;

void	*malloc(size_t size)
{
	// if (g_zones == NULL)
	// 	AllocateZone(size);



	int	*ret;
	printf("Zone Size : %lu\n", sizeof(t_zone));
	printf("Allocated Zone Size : %lu\n", sizeof(t_allocatedZone));
	if (g_zones == NULL)
		printf("g_zones is NULL\n");
	g_zones = (t_zone *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (g_zones != NULL)
		printf("g_zones is not NULL\n");
	return ((void *)NULL);
}
