/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:22:40 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/17 16:49:33 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if ((size_t)dst - (size_t)src < n)
	{
		i = n - 1;
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
				i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*a = malloc(sizeof(char) * 5);
	char	*b = malloc(sizeof(char) * 5);
	char	*src = "ahmet";

	printf("org : %s, ", memmove(a, src, 4));
	printf("ft_ : %s", ft_memmove(b ,src , 4));
}
*/
