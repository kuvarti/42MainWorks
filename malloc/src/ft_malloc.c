/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:03 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 14:08:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_zone	*g_zones = NULL;

void	*malloc(size_t size)
{
	void *ret;

	ret = AllocateManager(size);
	return (ret);
}
