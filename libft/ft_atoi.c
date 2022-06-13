/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:26:38 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/13 12:28:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

static int	ft_isspace(const char *chr, int *index)
{
	*index = 0;
	while ((chr[index] >= 9 && chr[index] <= 13) || chr[index] == ' ')
		index++;
}

static int	ft_isaret(char c, int *index)
{
	int	isaret;

	isaret = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			isaret *= -1;
		*index += 1;
	}
	return (isaret);
}

int	ft_atoi(const char *nptr)
{
	int	ret_val;
	int	index;
	int	isaret;

	ret_val = 0;
	if (*nptr == '\0')
		return (0);
	ft_isspace(nptr, &index);
	isaret = ft_isaret(nptr[index], &index);
	while (nptr[index] == '0')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		ret_val = (ret_val * 10) + (nptr[index++] - '0');
		if (ret_val <= 0)
		{
			if (isaret == -1)
				return (0);
			return (-1);
		}
	}
	return (ret_val * isaret);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("org : %d, my : %d", atoi("-125"), ft_atoi("-125"));
}
*/
