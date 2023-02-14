/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimaputils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:03:27 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 07:29:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawsquare(t_cub3d *game, double x, double y, int color)
{
	int	_x;
	int	_y;
	int	i;
	int	j;

	_x = x * 36;
	_x -= 18;
	i = _x + 36;
	while (_x < i)
	{
		_y = y * 36;
		_y -= 18;
		j = _y + 36;
		while (_y < j)
		{
			//if (_x + 18 > MMAPW || _y + 18 > MMAPH)
			//	break ;
			my_mlx_pixel_put(game->mmap->img, _x + 18, _y + 18, color);
			_y++;
		}
		_x++;
	}
	return ;
}
