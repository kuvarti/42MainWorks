/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 00:53:39 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bitir(t_cub3d *cub3d)
{
	exit(mlx_destroy_window(cub3d->mlx, cub3d->win));
	return (1);
}

//TODO(s)
int	initialize_player(t_cub3d *game)
{
	int	i;
	int	j;

	game->player = malloc(sizeof(t_character));
	i = -1;
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr("NSEW", game->map->map[i][j]))
			{
				game->player->posX = (double)j;
				game->player->posY = (double)i;
				return (1);
			}
		}
	}
	return (0);
}

int	initialize(t_cub3d *init, char **argv)
{
	(init)->mlx = mlx_init();
	if (!((init)->mlx))
		return (0);
	if (!mapgenerate(init, argv[1]))
		return (0);
	init->win = mlx_new_window(init->mlx, SCREEN_WIDTH, SCREEN_HEIGH, "cub3d");
	if  (!((init)->win))
		return (0);
	mlx_hook((init)->win, ON_DESTROY, 1L << 0, bitir, init);
	if (!initialize_player(init))
		return (0);
	return (1);
}
