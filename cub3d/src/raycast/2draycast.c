/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/03 01:04:44 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	summonray(t_cub3d *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
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
		if (!game->map->map[ray->map.y])
			break ;
		else if (game->map->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
	return (*ray);
}

t_raycast	getwalllength(t_cub3d *game, t_raycast *ray)
{
	ray->draw.perpwalldist = getperpwalldist(ray);
	ray->draw.lineheight = (int)(SCREEN_HEIGH / ray->draw.perpwalldist);
	ray->draw.drawwall.x = -ray->draw.lineheight / 2 + SCREEN_HEIGH / 2;
	if (ray->draw.drawwall.x < 0)
		ray->draw.drawwall.x = 0;
	ray->draw.drawwall.y = ray->draw.lineheight / 2 + SCREEN_HEIGH / 2;
	if (ray->draw.drawwall.y > SCREEN_HEIGH)
		ray->draw.drawwall.y = SCREEN_HEIGH;
	*ray = setwall(game, ray);
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
		ray = getwalllength(game, &ray);
		drawvertical(x, game, &ray);
	}
}
