/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:48 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 07:49:44 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setframe(t_cub3d *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MMAPH)
	{
		x = -1;
		while (++x < MMAPW)
		{
			if (y == 0 || y == MMAPH - 1)
				my_mlx_pixel_put(game->mmap->img, x, y, 0x440088);
			else if (x == 0 || x == MMAPW - 1)
				my_mlx_pixel_put(game->mmap->img, x, y, 0x440088);
		}
	}
}

void	getminimap(t_cub3d *game)
{
	int	x;
	int	y;
	int	_x;
	int	_y;

	_y = 0;
	y = (int)game->player->pos.y - 3;
	while (++y <= (int)game->player->pos.y + 2)
	{
		_x = 0;
		x = (int)game->player->pos.x - 3;
		while (++x <= (int)game->player->pos.x + 2)
		{
			if (y == -1)
				drawsquare(game, _x, _y, 0);
			else if (game->map->map[y] && game->map->map[y][x] == '1')
				drawsquare(game, _x, _y, 0xff1f2f);
			else
				drawsquare(game, _x, _y, 0);
			_x++;
		}
		_y++;
	}
	setframe(game);
	mlx_put_image_to_window(game->mlx, game->win, game->mmap->img->img, 1, 1);
}
