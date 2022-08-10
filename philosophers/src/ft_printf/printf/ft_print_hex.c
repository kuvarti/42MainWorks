/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:30:36 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 21:04:21 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char	*ten6;

	ret = ft_putstr("0x");
	if (hex == 0)
		return (ret + ft_putchar('0'));
	i = hexlen(hex);
	ten6 = malloc(i + 1);
	ten6[i--] = 0;
	while (hex > 0)
	{
		ten6[i--] = base[hex % 16];
		hex /= 16;
	}
	i = 0;
	while (ten6[i])
		ret += ft_putchar(ten6[i++]);
	free(ten6);
	return (ret);
}

int	ft_puthex(unsigned int hex, char *base)
{
	int		i;
	int		ret;
	char	*ten6;

	if (hex == 0)
		return (ft_putchar('0'));
	i = hexlen(hex);
	ten6 = malloc(i + 1);
	ten6[i--] = 0;
	while (hex > 0)
	{
		ten6[i--] = base[hex % 16];
		hex /= 16;
	}
	ret = 0;
	i = 0;
	while (ten6[i])
		ret += ft_putchar(ten6[i++]);
	free(ten6);
	return (ret);
}
