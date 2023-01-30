/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:17:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/30 21:01:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn(t_cub3d *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->onkey.keyleft)
	{
		game->player->dir.x = game->player->dir.x * cos(-TURNSPEED)
			- game->player->dir.y * sin(-TURNSPEED);
		game->player->dir.y = olddirx * sin(-TURNSPEED)
			+ game->player->dir.y * cos(-TURNSPEED);
		game->player->plane.x = game->player->plane.x * cos(-TURNSPEED)
			- game->player->plane.y * sin(-TURNSPEED);
		game->player->plane.y = oldplanex * sin(-TURNSPEED)
			+ game->player->plane.y * cos(-TURNSPEED);
		return ;
	}
	game->player->dir.x = game->player->dir.x * cos(TURNSPEED)
		- game->player->dir.y * sin(TURNSPEED);
	game->player->dir.y = olddirx * sin(TURNSPEED)
		+ game->player->dir.y * cos(TURNSPEED);
	game->player->plane.x = game->player->plane.x * cos(TURNSPEED)
		- game->player->plane.y * sin(TURNSPEED);
	game->player->plane.y = oldplanex * sin(TURNSPEED)
		+ game->player->plane.y * cos(TURNSPEED);
}

void	setpos(t_cub3d *game, double newposx, double newposy, char mod)
{
	double	*posx;
	double	*posy;

	posx = &(game->player->pos.x);
	posy = &(game->player->pos.y);
	if (mod == '-')
	{
		if (!(game->map->map[(int)(*posy - (newposy * WALKINGSPEED * WLK))]))
			return ;
		if (game->map->map[(int)(*posy - (newposy * WALKINGSPEED * WLK))] \
				[(int)(*posx - (newposx * WALKINGSPEED * WLK))] == '1')
			return ;
		game->player->pos.x -= newposx * (WALKINGSPEED * WLK);
		game->player->pos.y -= newposy * (WALKINGSPEED * WLK);
	}
	else if (mod == '+')
	{
		if (!(game->map->map[(int)(*posy + (newposy * WALKINGSPEED * WLK))]))
			return ;
		if (game->map->map[(int)(*posy + (newposy * WALKINGSPEED * WLK))] \
				[(int)(*posx + (newposx * WALKINGSPEED * WLK))] == '1')
			return ;
		game->player->pos.x += newposx * (WALKINGSPEED * WLK);
		game->player->pos.y += newposy * (WALKINGSPEED * WLK);
	}
}
//	(int)(*posX + (newposx * WALKINGSPEED * WLK))
//	(int)(*posY + (newposy * WALKINGSPEED * WLK))

int	move(t_cub3d *game)
{
	if (game->onkey.keyw)
		setpos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->onkey.keys)
		setpos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->onkey.keyd)
		setpos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->onkey.keya)
		setpos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->onkey.keyleft || game->onkey.keyright)
		turn(game);
	return (retmove(game));
}

int	retmove(t_cub3d *game)
{
	if (game->onkey.keyw || game->onkey.keys || game->onkey.keya
		|| game->onkey.keyd || game->onkey.keyleft || game->onkey.keyright)
		return (1);
	else
		return (0);
}
