/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:52:37 by aeryilma          #+#    #+#             */
/*   Updated: 2022/03/07 21:01:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "unistd.h"
# include "stdlib.h"
# include "../libft/libft.h"

int	ft_printf(const char *ref, ...);
int	ft_putptr(unsigned long hex, char *base);
int	ft_puthex(unsigned int hex, char *base);
int	ft_putunbr(unsigned int n);
int	ft_putstr(char const *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif
