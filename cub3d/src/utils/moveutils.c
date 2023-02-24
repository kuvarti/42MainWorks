/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:17:25 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/24 22:34:47 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn(t_cub3d *game)
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

void	cursorturn(t_cub3d *game, int key)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (key == KEY_LEFT)
	{
		game->player->dir.x = game->player->dir.x * cos(-(TURNSPEED * 2))
			- game->player->dir.y * sin(-(TURNSPEED * 2));
		game->player->dir.y = olddirx * sin(-(TURNSPEED * 2))
			+ game->player->dir.y * cos(-(TURNSPEED * 2));
		game->player->plane.x = game->player->plane.x * cos(-(TURNSPEED * 2))
			- game->player->plane.y * sin(-(TURNSPEED * 2));
		game->player->plane.y = oldplanex * sin(-(TURNSPEED * 2))
			+ game->player->plane.y * cos(-(TURNSPEED * 2));
		return ;
	}
	game->player->dir.x = game->player->dir.x * cos((TURNSPEED * 2))
		- game->player->dir.y * sin((TURNSPEED * 2));
	game->player->dir.y = olddirx * sin((TURNSPEED * 2))
		+ game->player->dir.y * cos((TURNSPEED * 2));
	game->player->plane.x = game->player->plane.x * cos((TURNSPEED * 2))
		- game->player->plane.y * sin((TURNSPEED * 2));
	game->player->plane.y = oldplanex * sin((TURNSPEED * 2))
		+ game->player->plane.y * cos((TURNSPEED * 2));
}

static double	getdistance(double newpos)
{
	return (newpos * WALKINGSPEED * WLK);
}

void	setpos(t_cub3d *game, double newposx, double newposy, char mod)
{
	double	*posx;
	double	*posy;

	posx = &(game->player->pos.x);
	posy = &(game->player->pos.y);
	if (mod == '-')
	{
		if (!(game->map->map[(int)(*posy - getdistance(newposy))]))
			return ;
		if (ft_strchr("1C", game->map->map[(int)(*posy - getdistance(newposy))]
			[(int)(*posx - getdistance(newposx))]))
			return ;
		game->player->pos.x -= newposx * (WALKINGSPEED * WLK);
		game->player->pos.y -= newposy * (WALKINGSPEED * WLK);
	}
	else if (mod == '+')
	{
		if (!(game->map->map[(int)(*posy + getdistance(newposy))]))
			return ;
		if (ft_strchr("1C", game->map->map[(int)(*posy + getdistance(newposy))]
			[(int)(*posx + getdistance(newposx))]))
			return ;
		game->player->pos.x += newposx * (WALKINGSPEED * WLK);
		game->player->pos.y += newposy * (WALKINGSPEED * WLK);
	}
}
//	(int)(*posX + (newposx * WALKINGSPEED * WLK))
//	(int)(*posY + (newposy * WALKINGSPEED * WLK))
