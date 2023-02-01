/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:18:29 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/02 00:43:09 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	getscreen(t_cub3d *game)
{
	raycast(game);
	//mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
