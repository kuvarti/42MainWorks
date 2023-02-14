/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:18:29 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/13 20:06:55 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fillimage(int x, t_cub3d *game, t_raycast *ray)
{
	size_t	y;
	t_data	*tmp;

	y = -1;
	tmp = game->texture.xpm[ray->draw.wall];
	if (game->map->map[ray->map.y][ray->map.x] == 'C')
		tmp = game->texture.xpm[0];
	while (++y < SCREEN_HEIGH)
	{
		if (y < (size_t)ray->draw.drawwall.x)
			my_mlx_pixel_put(game->img, x, y, game->texture.top);
		else if (y < (size_t)ray->draw.drawwall.y)
		{
			ray->draw.tex.y = (int)ray->draw.texpos & (64 - 1);
			ray->draw.texpos += ray->draw.step;
			ray->draw.color = \
				get_texture_color(tmp,
					ray->draw.tex.x, ray->draw.tex.y);
			my_mlx_pixel_put(game->img, x, y, ray->draw.color);
		}
		else
		{
			my_mlx_pixel_put(game->img, x, y, game->texture.bot);
		}
	}
}

void	drawvertical(int x, t_cub3d *game, t_raycast *ray)
{
	ray->draw.wallx -= floor(ray->draw.wallx);
	ray->draw.tex.x = (int)(ray->draw.wallx * (double)(64));
	if (ray->side == 0 && ray->raydir.x > 0)
		ray->draw.tex.x = 64 - ray->draw.tex.x - 1;
	if (ray->side == 1 && ray->raydir.y < 0)
		ray->draw.tex.x = 64 - ray->draw.tex.x - 1;
	ray->draw.step = 1.0 * 64 / ray->draw.lineheight;
	ray->draw.texpos = \
		(ray->draw.drawwall.x - SCREEN_HEIGH / 2 + ray->draw.lineheight / 2)
		* ray->draw.step;
	fillimage(x, game, ray);
}
