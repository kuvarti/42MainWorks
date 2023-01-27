/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:49:05 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/27 06:11:11 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getplayerdir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->angle = (3 * PI) / 2;
		return (1);
	}
	else if (c == 'E')
	{
		game->player->angle = 0;
		return (1);
	}
	return (0);
}

int	initialize_player(t_cub3d *game)
{
	int	i;
	int	j;

	i = -1;
	game->player = malloc(sizeof(t_character));
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->map[i][j]))
			{
				game->player->pos.X = (double)j + 0.5;
				game->player->pos.Y = (double)i + 0.5;
				game->player->plane.X = 0;
				game->player->plane.Y = 1;
				game->player->dir.X = -1;
				game->player->dir.Y = 0;
				return (getplayerdir(game, game->map->map[i][j]));
			}
		}
	}
	return (0);
}
