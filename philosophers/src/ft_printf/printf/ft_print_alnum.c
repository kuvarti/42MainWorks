/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alnum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:04 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 21:04:20 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char const *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr(int n)
{
	char	*print;
	int		ret;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n == 0)
		return (ft_putchar('0'));
	print = ft_itoa(n);
	ret = ft_putstr(print);
	free(print);
	return (ret);
}
