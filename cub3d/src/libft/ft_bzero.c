/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:53:10 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/17 11:32:34 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)s) = 0;
		s++;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	deneme[6] = "ahmet";
	printf("before : %s, ", deneme);
	ft_bzero(deneme, sizeof(deneme));
	printf("after : %s", deneme);
}
*/
