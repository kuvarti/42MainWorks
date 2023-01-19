/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:11:21 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 23:18:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish(t_cub3d *cub3d)
{
	exit(mlx_destroy_window(cub3d->mlx, cub3d->win));
	return (1);
}

static void	turn(t_cub3d *game, int key)
{
	if (key == KEY_LEFT)
	{
		game->player->angle -= TURNSPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->delta.X = cos(game->player->angle) * 5;
		game->player->delta.Y = sin(game->player->angle) * 5;
	}
	else if (key == KEY_RIGHT)
	{
		game->player->angle += TURNSPEED;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->delta.X = cos(game->player->angle) * 5;
		game->player->delta.Y = sin(game->player->angle) * 5;
	}
}

int	getkeys(int	keycode, t_cub3d *game)
{
	if (keycode == KEY_ESC)
		finish(game);
	else if (keycode == KEY_W)
		game->player->pos.Y -= WALKINGSPEED;
	else if (keycode == KEY_S)
		game->player->pos.Y += WALKINGSPEED;
	else if (keycode == KEY_A)
		game->player->pos.X -= WALKINGSPEED;
	else if (keycode == KEY_D)
		game->player->pos.X += WALKINGSPEED;
	if (keycode == KEY_LEFT)
		turn(game, KEY_LEFT);
	else if (keycode == KEY_RIGHT)
		turn(game, KEY_RIGHT);
	ciz(game);
	return (1);
}
