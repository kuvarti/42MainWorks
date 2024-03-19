/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:30:36 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 13:29:57 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hexlen(unsigned long hex)
{
	int	i;

	i = 0;
	while (hex > 0)
	{
		hex /= 16;
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long hex, char *base)
{
	int		i;
	int		ret;
	char	*on6;

	ret = ft_putstr("0x");
	if (hex == 0)
		return (ret + ft_putchar('0'));
	i = hexlen(hex);
	on6 = malloc(i + 1);
	on6[i--] = 0;
	while (hex > 0)
	{
		on6[i--] = base[hex % 16];
		hex /= 16;
	}
	i = 0;
	while (on6[i])
		ret += ft_putchar(on6[i++]);
	free(on6);
	return (ret);
}

int	ft_puthex(unsigned int hex, char *base)
{
	int		i;
	int		ret;
	char	*on6;

	if (hex == 0)
		return (ft_putchar('0'));
	i = hexlen(hex);
	on6 = malloc(i + 1);
	on6[i--] = 0;
	while (hex > 0)
	{
		on6[i--] = base[hex % 16];
		hex /= 16;
	}
	ret = 0;
	i = 0;
	while (on6[i])
		ret += ft_putchar(on6[i++]);
	free(on6);
	return (ret);
}
