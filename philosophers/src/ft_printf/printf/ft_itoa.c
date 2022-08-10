/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:57:02 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 17:59:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_arraylen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_10base(int us)
{
	int	ret;

	ret = 1;
	while (us > 0)
	{
		ret *= 10;
		us--;
	}
	return (ret);
}

static char	*maxmin(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		lenght;
	int		index;

	lenght = ft_arraylen(n);
	index = 0;
	if (n == 0 || n == -2147483648)
		return (maxmin(n));
	ret = malloc(sizeof(char) * lenght + 1);
	if (!ret)
		return (0);
	if (n < 0 && lenght--)
	{
		ret[index++] = '-';
		n *= -1;
	}
	while (lenght > 0)
	{
		ret[index++] = (n / (ft_10base(lenght - 1))) + '0';
		n %= ft_10base(lenght - 1);
		lenght--;
	}
	ret[index] = '\0';
	return (ret);
}
