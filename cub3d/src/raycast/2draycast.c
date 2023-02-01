/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/01 22:34:25 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	summonray(t_cub3d *game, t_raycast *ray)
{
	while(ray->hit == 0)
	{
		if(ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if(!game->map->map[ray->map.y])
			break ;
		else if (game->map->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
	return (*ray);
}

void	raycast(t_cub3d *game)
{
	int			x;
	t_raycast	ray;

	x = -1;
	ray = initraycast(game);
	while (++x < SCREEN_WIDTH)
	{
		ray = raycastloopstart(&ray, x);
		ray = summonray(game, &ray);

		double perpWallDist;
		if(ray.side == 0) perpWallDist = (ray.sidedist.x - ray.deltadist.x);
		else          perpWallDist = (ray.sidedist.y - ray.deltadist.y);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGH/ perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGH / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGH / 2;
		if(drawEnd >= SCREEN_HEIGH) drawEnd = SCREEN_HEIGH - 1;

		//choose wall color
		int color = 0xffffff;

		int pitch = 100;

		// side 1 ise N S
		// side 0 ise W E
		double wallX;
		int	wall;
		//give x and y sides different brightness
		if (ray.side == 0)
		{
			wallX = game->player->pos.y + perpWallDist * ray.raydir.y;
			if (ray.map.x < game->player->pos.x)
				wall = 3;
			else
				wall = 2;
		}
		else
		{
			wallX = game->player->pos.x + perpWallDist * ray.raydir.x;
			if (ray.map.y < game->player->pos.y)
				wall = 1;
			else
				wall = 0;
		}
		wallX -= floor(wallX);	//todo

		int	texX = (int)(wallX * (double)(64));
		if (ray.side == 0 && ray.raydir.x > 0)
			texX = 64 - texX - 1;
		if (ray.side == 1 && ray.raydir.y < 0)
			texX = 64 - texX - 1;
		//draw the pixels of the stripe as a vertical line

		double step = 1.0 * 64 / lineHeight;
		double texPos = (drawStart - pitch - SCREEN_HEIGH / 2 + lineHeight / 2) * step;
		for (size_t y = 0; y < drawStart; y++)
		{
			my_mlx_pixel_put(game->img, x, y, game->texture.top);
		}
		for (size_t y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (64 - 1);
			texPos += step;
			color = get_texture_color(game->texture.xpm[wall], texX, texY);
			my_mlx_pixel_put(game->img, x, y, color);
		}
		for (size_t y = drawEnd; y < SCREEN_HEIGH; y++)
		{
			my_mlx_pixel_put(game->img, x, y, game->texture.bot);
		}
	}
}

void	drawline(t_cub3d *game, t_vectord start, t_vectord end, int color)
{
    int dx = end.x - (start.x * 100 + 50);
    int dy = end.y - (start.y * 100 + 50);
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = start.x * 100 + 50;
    float Y = start.y * 100 + 50;
    for (int i = 0; i <= steps; i++)
    {
		my_mlx_pixel_put(game->img, X, Y, color);
        X += Xinc;
        Y += Yinc;
    }
}

void	drawsquare(t_cub3d *game, double x, double y, int color)
{
	int	_x;
	int	_y;
	int	i;
	int	j;

	if (color == 0)
	{
		_x = x * 100;
		_x -=50;
		i = _x + 100;
		while (_x < i)
		{
			_y = y * 100;
			_y -=50;
			j = _y + 100;
			while (_y < j)
			{
				my_mlx_pixel_put(game->img, _x + 50, _y + 50, color);
				_y++;
			}
			_x++;
		}
		return ;
	}
}
