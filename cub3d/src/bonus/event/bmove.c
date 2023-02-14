/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:34:26 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 05:43:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
