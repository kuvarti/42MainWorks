/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:51:03 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:44:17 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	resolver(va_list arg, char f)
{
	if (f == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (f == 'd' || f == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (f == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	else if (f == 'p')
		return (ft_putptr(va_arg(arg, unsigned long), "0123456789abcdef"));
	else if (f == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (f == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *ref, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, ref);
	while (*ref)
	{
		if (*ref == '%')
		{
			ref++;
			if (*ref == '%')
				total += ft_putchar('%');
			else
				total += resolver(args, *ref);
		}
		else
			total += ft_putchar(*ref);
		ref++;
	}
	va_end(args);
	return (total);
}
