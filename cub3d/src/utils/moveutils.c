/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:17:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/27 05:35:36 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn(t_cub3d *game)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = game->player->dir.X;
	oldPlaneX = game->player->plane.X;
	if (game->onkey.keyright)
	{
		game->player->angle -= TURNSPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
		game->player->dir.X = game->player->dir.X * cos(-TURNSPEED) - game->player->dir.Y * sin(-TURNSPEED);
		game->player->dir.Y = oldDirX * sin(-TURNSPEED) + game->player->dir.Y * cos(-TURNSPEED);
		game->player->plane.X = game->player->plane.X * cos(-TURNSPEED) - game->player->plane.Y * sin(-TURNSPEED);
		game->player->plane.Y = oldPlaneX * sin(-TURNSPEED) + game->player->plane.Y * cos(-TURNSPEED);
	}
	else if (game->onkey.keyleft)
	{
		game->player->angle += TURNSPEED;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
		game->player->dir.X = game->player->dir.X * cos(TURNSPEED) - game->player->dir.Y * sin(TURNSPEED);
		game->player->dir.Y = oldDirX * sin(TURNSPEED) + game->player->dir.Y * cos(TURNSPEED);
		game->player->plane.X = game->player->plane.X * cos(TURNSPEED) - game->player->plane.Y * sin(TURNSPEED);
		game->player->plane.Y = oldPlaneX * sin(TURNSPEED) + game->player->plane.Y * cos(TURNSPEED);
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
		game->player->pos.X += game->player->dir.X * getmvspeed();
		game->player->pos.Y += game->player->dir.Y * getmvspeed();
	}
	if (game->onkey.keys)
	{
		game->player->pos.X -= game->player->dir.X * getmvspeed();
		game->player->pos.Y -= game->player->dir.Y * getmvspeed();
	}
	//if (game->onkey.keya)
	//{
	//	game->player->pos.X -= game->player->dir.X * getmvspeed();
	//	game->player->pos.Y -= sin(game->player->angle + VERA) * getmvspeed();
	//}
	//if (game->onkey.keyd)
	//{
	//	game->player->pos.X += cos(game->player->angle + VERA) * getmvspeed();
	//	game->player->pos.Y += sin(game->player->angle + VERA) * getmvspeed();
	//}
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
