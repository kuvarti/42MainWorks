/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 06:13:56 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 06:48:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mousemove(int x, int y, t_cub3d *game)
{
	if (x % 5 != 0)
		return (0);
	if (x > game->onkey.cursorpos.x)
		cursorturn(game, KEY_RIGHT);
	else if (x == SCREEN_WIDTH / 2)
		return (0);
	else
		cursorturn(game, KEY_LEFT);
	y = y;
	mlx_mouse_move(game->mlx, game->win, SCREEN_WIDTH / 2, SCREEN_HEIGH / 2);
	mlx_mouse_hide(game->mlx, game->win);
	getscreen(game);
	return (1);
}
