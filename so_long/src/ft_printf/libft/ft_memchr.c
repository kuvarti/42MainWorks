/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:25:43 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/17 12:05:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	if (n == 0 && (c >= 0 && c <= 255))
		return (NULL);
	while (index < n && (((unsigned char *)s)[index] != (unsigned char)c))
	{
		if (index == n - 1)
			return (NULL);
		index++;
	}
	return (&((unsigned char *)s)[index]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*p = "deneme";
	char	b = 'e';

	printf("org : %p, mine : %p", memchr(p,b,4), ft_memchr(p,b,4));
}
*/
