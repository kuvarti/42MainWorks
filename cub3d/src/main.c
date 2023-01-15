/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:29:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/15 05:00:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int bitir(t_cub3d *cub3d)
{
	exit(mlx_destroy_window(cub3d->mlx, cub3d->win));
}

int initialize(t_cub3d *init)
{
	char	*title;

	(init)->mlx = mlx_init();
	if (!((init)->mlx))
		return (1);
	title = malloc(6);
	title = "cub3d\0";
	(init)->win = mlx_new_window((init)->mlx, 1280, 720, title);
	if  (!((init)->win))
		return (1);
	mlx_hook((init)->win, ON_DESTROY, 1L << 0, bitir, init);
	return 0;
}

int main()
{
	t_cub3d	*game;

	game = malloc(sizeof(t_cub3d));
	initialize(game);
	mlx_loop(game->mlx);
}
