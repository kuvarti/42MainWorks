/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:46:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/17 16:42:21 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dest && !src)
		return (0);
	if (dest == src)
		return (dest);
	tmp = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (tmp);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char		*ds1 = malloc(sizeof(char) * 5);
	char		*ds2 = malloc(sizeof(char) * 5);
	const char	*sr = "ahmet";

	printf("mine : %s, ", ft_memcpy(ds2, sr, 5));
	printf("org : %s, ", memcpy(ds1, sr, 5));
}
*/
