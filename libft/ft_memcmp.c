/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:56:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/17 12:59:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < (n - 1))
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			break ;
		index++;
	}
	return (((unsigned char *)s1)[index] - (((unsigned char *)s2)[index]));
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*p1 = "bubir";
	char	*p2 = "buiki";

	printf("org : %d, mine : %d", memcmp(p1,p2,5), ft_memcmp(p1,p2,5));
}
*/
