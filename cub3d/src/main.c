/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:29:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/16 01:42:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_cub3d	*game;

	game = malloc(sizeof(t_cub3d));
	if (!initialize(game))
		return (0);
	mlx_loop(game->mlx);
}
