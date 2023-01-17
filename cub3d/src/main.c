/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:29:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/17 02:39:57 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_cub3d	*game;

	if (argc != 2)
		return (printf("error: please run with single map: ./cub3d eg.cub\n"));
	game = malloc(sizeof(t_cub3d));
	if (!initialize(game, argv))
		return (0);
	//mlx_loop(game->mlx);
	printf("\n\nloop started\n");
}
