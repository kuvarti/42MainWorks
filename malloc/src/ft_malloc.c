/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:03 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/14 13:21:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*malloc(size_t size)
{
	int	*ret;
	size_t	len;

	if (size <= 0)
		return (NULLPTR);
	if (size <= TINY)
		size = TINY;
	len = size + sizeof(size);
	ret = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	*ret = len;
	return ((void *)ret);
}
