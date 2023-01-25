/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:49:05 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/25 03:53:39 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setdelta(t_cub3d *game)
{
	game->player->delta.X = cos(game->player->angle) * 5;
	game->player->delta.Y = sin(game->player->angle) * 5;
}

int	getplayerdir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->angle = (3 * PI) / 2;
		setdelta(game);
		return (1);
	}
	else if (c == 'E')
	{
		game->player->angle = 0;
		setdelta(game);
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
				game->player->pos.X = (double)j;
				game->player->pos.Y = (double)i;
				return (getplayerdir(game, game->map->map[i][j]));
			}
		}
	}
	return (0);
}
