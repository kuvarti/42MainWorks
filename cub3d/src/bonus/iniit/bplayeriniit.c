/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:49:05 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/30 21:01:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setplane(t_cub3d *game, char d)
{
	if (d == 'N')
	{
		game->player->plane.x = FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'S')
	{
		game->player->plane.x = -FOV;
		game->player->plane.y = 0;
	}
	else if (d == 'W')
	{
		game->player->plane.x = 0;
		game->player->plane.y = -FOV;
	}
	else if (d == 'E')
	{
		game->player->plane.x = 0;
		game->player->plane.y = FOV;
	}
}

void	getplayerdir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
	}
	else if (c == 'S')
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
	}
	else if (c == 'W')
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
	}
	else if (c == 'E')
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
	}
	setplane(game, c);
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
				game->player->pos.x = (double)j + 0.5;
				game->player->pos.y = (double)i + 0.5;
				getplayerdir(game, game->map->map[i][j]);
				return (1);
			}
		}
	}
	return (0);
}
