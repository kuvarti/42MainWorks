/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:03 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/15 15:39:52 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>

t_zone	*g_zones = NULL;

void	*malloc(size_t size)
{
	void *ret;

	ret = AllocateManager(size);
	printf("Zone Size : %lu\n", sizeof(t_zone));
	printf("Allocated Zone Size : %lu\n", g_zones->used);
	return (ret);
}
