/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:17:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/25 04:22:01 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn(t_cub3d *game)
{
	if (game->onkey.keyleft)
	{
		game->player->angle -= TURNSPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->delta.X = cos(game->player->angle) * 5;
		game->player->delta.Y = sin(game->player->angle) * 5;
	}
	else if (game->onkey.keyright)
	{
		game->player->angle += TURNSPEED;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->delta.X = cos(game->player->angle) * 5;
		game->player->delta.Y = sin(game->player->angle) * 5;
	}
}

float	getmvspeed()
{
	return (WALKINGSPEED * WLK);
}

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
	{
		game->player->pos.X += cos(game->player->angle) * (WALKINGSPEED * WLK);
		game->player->pos.Y += sin(game->player->angle) * (WALKINGSPEED * WLK);
	}
	if (game->onkey.keys)
	{
		game->player->pos.X -= cos(game->player->angle) * (WALKINGSPEED * WLK);
		game->player->pos.Y -= sin(game->player->angle) * (WALKINGSPEED * WLK);
	}
	if (game->onkey.keya)
	{
		game->player->pos.X -= cos(game->player->angle + VERA) * getmvspeed();
		game->player->pos.Y -= sin(game->player->angle + VERA) * getmvspeed();
	}
	if (game->onkey.keyd)
	{
		game->player->pos.X += cos(game->player->angle + VERA) * getmvspeed();
		game->player->pos.Y += sin(game->player->angle + VERA) * getmvspeed();
	}
	if (game->onkey.keyleft || game->onkey.keyright)
		turn(game);
	return (retmove(game));
}

int	retmove(t_cub3d *game)
{
	if (game->onkey.keyw || game->onkey.keys || game->onkey.keya ||
			game->onkey.keyd || game->onkey.keyleft || game->onkey.keyright)
		return (1);
	else
		return (0);
}
