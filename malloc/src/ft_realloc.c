/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:14:59 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:32:01 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*realloc(void *ptr, size_t size)
{

	write(1, "realloc\n", 8);
	void *ret;
	ret = ReAllocateManager(ptr, size);
	return (ret);
}
