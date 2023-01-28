/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:17:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/28 20:10:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn(t_cub3d *game)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = game->player->dir.X;
	oldPlaneX = game->player->plane.X;
	if (game->onkey.keyleft)
	{
		game->player->dir.X = game->player->dir.X * cos(-TURNSPEED)
				- game->player->dir.Y * sin(-TURNSPEED);
		game->player->dir.Y = oldDirX * sin(-TURNSPEED)
				+ game->player->dir.Y * cos(-TURNSPEED);
		game->player->plane.X = game->player->plane.X * cos(-TURNSPEED)
				- game->player->plane.Y * sin(-TURNSPEED);
		game->player->plane.Y = oldPlaneX * sin(-TURNSPEED)
				+ game->player->plane.Y * cos(-TURNSPEED);
		return ;
	}
	game->player->dir.X = game->player->dir.X * cos(TURNSPEED)
			- game->player->dir.Y * sin(TURNSPEED);
	game->player->dir.Y = oldDirX * sin(TURNSPEED)
			+ game->player->dir.Y * cos(TURNSPEED);
	game->player->plane.X = game->player->plane.X * cos(TURNSPEED)
			- game->player->plane.Y * sin(TURNSPEED);
	game->player->plane.Y = oldPlaneX * sin(TURNSPEED)
			+ game->player->plane.Y * cos(TURNSPEED);
}

void	setpos(t_cub3d *game, double newposx, double newposy, char mod)
{
	double	*posX;
	double	*posY;

	posX = &(game->player->pos.X);
	posY = &(game->player->pos.Y);
	if (mod == '-')
	{
		if (!(game->map->map[(int)(*posY - (newposy * WALKINGSPEED * WLK))]))
			return ;
		if (game->map->map[(int)(*posY - (newposy * WALKINGSPEED * WLK))]\
				[(int)(*posX- (newposx * WALKINGSPEED * WLK))] == '1')
			return ;
		game->player->pos.X -= newposx * (WALKINGSPEED * WLK);
		game->player->pos.Y -= newposy * (WALKINGSPEED * WLK);
	}
	else if (mod == '+')
	{
		if (!(game->map->map[(int)(*posY + (newposy * WALKINGSPEED * WLK))]))
			return ;
		if (game->map->map[(int)(*posY + (newposy * WALKINGSPEED * WLK))] \
				[(int)(*posX + (newposx * WALKINGSPEED * WLK))] == '1')
			return ;
		game->player->pos.X += newposx * (WALKINGSPEED * WLK);
		game->player->pos.Y += newposy * (WALKINGSPEED * WLK);
	}
}
//	(int)(*posX + (newposx * WALKINGSPEED * WLK))
//	(int)(*posY + (newposy * WALKINGSPEED * WLK))

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
		setpos(game, game->player->dir.X, game->player->dir.Y, '+');
	if (game->onkey.keys)
		setpos(game, game->player->dir.X, game->player->dir.Y, '-');
	if (game->onkey.keyd)
		setpos(game, game->player->plane.X, game->player->plane.Y, '+');
	if (game->onkey.keya)
		setpos(game, game->player->plane.X, game->player->plane.Y, '-');
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
