/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doorcontrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:52:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 06:28:38 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	xordoor(t_cub3d *game, int x, int y)
{
	if (game->map->map[y][x] == 'C')
		game->map->map[y][x] = 'O';
	else
		game->map->map[y][x] = 'C';
}

void	switchdoor(t_cub3d *game)
{
	t_vectori	cpos;

	cpos.x = game->player->pos.x;
	cpos.y = game->player->pos.y;
	if (game->map->map[cpos.y + 1]
		&& ft_strchr("OC", game->map->map[cpos.y + 1][cpos.x]))
		xordoor(game, cpos.x, cpos.y + 1);
	if (game->map->map[cpos.y - 1]
		&& ft_strchr("OC", game->map->map[cpos.y - 1][cpos.x]))
		xordoor(game, cpos.x, cpos.y - 1);
	if (game->map->map[cpos.y][cpos.x + 1]
		&& ft_strchr("OC", game->map->map[cpos.y][cpos.x + 1]))
		xordoor(game, cpos.x + 1, cpos.y);
	if (game->map->map[cpos.y][cpos.x - 1]
		&& ft_strchr("OC", game->map->map[cpos.y][cpos.x - 1]))
		xordoor(game, cpos.x - 1, cpos.y);
	getscreen(game);
}
