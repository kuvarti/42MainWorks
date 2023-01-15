/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/16 01:44:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int bitir(t_cub3d *cub3d)
{
	exit(mlx_destroy_window(cub3d->mlx, cub3d->win));
	return (1);
}

//TODO(s)
int	initialize_map(t_cub3d *init);
int	initialize_player(t_character *player);

int	initialize(t_cub3d *init)
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
