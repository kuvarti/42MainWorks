/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:33:30 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/18 00:48:28 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			f(index, &s[index]);
			index++;
		}
	}
}
/*
#include <stdio.h>
void	funct(unsigned int a, char *b)
{
	*b = *b+a;
}
int main()
{
	char dizi[] = "aaaaaaaaaaaaaaaa";
	ft_striteri(dizi, funct);
	printf("%s",dizi);
}
*/
