/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:51:03 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 21:02:46 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//denemek için

int	cozbunu(va_list arglist, char f)
{
	if (f == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(arglist, int)));
	else if (f == 'u')
		return (ft_putunbr(va_arg(arglist, unsigned int)));
	else if (f == 'p')
		return (ft_putptr(va_arg(arglist, unsigned long), "0123456789abcdef"));
	else if (f == 'x')
		return (ft_puthex(va_arg(arglist, unsigned int), "0123456789abcdef"));
	else if (f == 'X')
		return (ft_puthex(va_arg(arglist, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *ref, ...)
{
	int		ret;
	va_list	arglist;

	ret = 0;
	va_start(arglist, ref);
	while (*ref)
	{
		if (*ref == '%')
		{
			ref++;
			if (*ref == '%')
				ret += ft_putchar('%');
			else
				ret += cozbunu(arglist, *ref);
		}
		else
			ret += ft_putchar(*ref);
		ref++;
	}
	va_end(arglist);
	return (ret);
}
/*
#include "limits.h"
int	main(void)
{
	ft_printf("ft_uzunluk : %d", ft_printf("%u\n", -12));
	printf("n_uzunluk :%d\n",printf("\n%u\n", -12));
	return (0);
}
*/
