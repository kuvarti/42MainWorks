/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loopstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:08:23 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/02 01:18:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_raycast	initraycast(t_cub3d *game)
{
	t_raycast	ret;

	ret.pos.x = game->player->pos.x;
	ret.pos.y = game->player->pos.y;
	ret.plane.x = game->player->plane.x;
	ret.plane.y = game->player->plane.y;
	ret.dir.x = game->player->dir.x;
	ret.dir.y = game->player->dir.y;
	return (ret);
}

static t_raycast	*setsidedist(t_raycast *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
	}
	return (ray);
}

t_raycast	raycastloopstart(t_raycast *ray, int x)
{
	double	camerax;

	camerax = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->raydir.x = ray->dir.x + ray->plane.x * camerax;
	ray->raydir.y = ray->dir.y + ray->plane.y * camerax;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ray->deltadist.x = dabs(1 / ray->raydir.x);
	ray->deltadist.y = dabs(1 / ray->raydir.y);
	ray = setsidedist(ray);
	ray->hit = 0;
	return (*ray);
}
