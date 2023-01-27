/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 04:32:16 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/27 04:33:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

double	dabs(double n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}
