/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:48 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 05:34:18 by aeryilma         ###   ########.fr       */
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
	setframe(game);
	mlx_put_image_to_window(game->mlx, game->win, game->mmap->img->img, 1, 1);
}
