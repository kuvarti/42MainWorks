/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/18 02:01:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bitir(t_cub3d *cub3d)
{
	exit(mlx_destroy_window(cub3d->mlx, cub3d->win));
	return (1);
}

//TODO(s)
int	initialize_map(t_cub3d *init);
int	initialize_player(t_character *player);

int	initialize(t_cub3d *init, char **argv)
{
	(init)->mlx = mlx_init();
	if (!((init)->mlx))
		return (0);
	if (!mapgenerate(init, argv[1]))
		return (0);
	(init)->win = mlx_new_window((init)->mlx, 1280, 720, "cub3d");
	if  (!((init)->win))
		return (0);
	mlx_hook((init)->win, ON_DESTROY, 1L << 0, bitir, init);

	int i = 0;
	while (init->map[i])
		printf("%s\n", init->map[i++]);

	return (1);
}
