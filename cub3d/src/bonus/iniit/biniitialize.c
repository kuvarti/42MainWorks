/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biniitialize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 06:40:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_event(t_cub3d *game)
{
	game->onkey.keya = 0;
	game->onkey.keys = 0;
	game->onkey.keyd = 0;
	game->onkey.keyw = 0;
	game->onkey.keyup = 0;
	game->onkey.keydown = 0;
	game->onkey.keyleft = 0;
	game->onkey.keyright = 0;
	game->onkey.cursorpos.x = SCREEN_WIDTH / 2;
	game->onkey.cursorpos.y = SCREEN_HEIGH / 2;
	return (0);
}

void	initminimapimage(t_cub3d *game)
{
	t_minimap	*mmap;

	if (game->mmap)
		return ;
	mmap = malloc(sizeof(t_minimap));
	mmap->img = malloc(sizeof(t_data));
	mmap->img->img = mlx_new_image(game->mlx, MMAPW, MMAPH);
	mmap->img->addr = \
	mlx_get_data_addr(mmap->img->img, &mmap->img->bits_per_pixel,
			&mmap->img->line_length, &mmap->img->endian);
	game->mmap = mmap;
}

int	initialize_image(t_cub3d *game)
{
	initminimapimage(game);
	game->img = malloc(sizeof(t_data));
	game->img->img = mlx_new_image(game->mlx, 1920, 1080);
	game->img->addr = \
	mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
			&game->img->line_length, &game->img->endian);
	if (!(game->img->img) || !(game->img->addr))
		return (0);
	else
		return (1);
}

int	initialize(t_cub3d *init, char **argv)
{
	(init)->mlx = mlx_init();
	if (!((init)->mlx))
		return (0);
	if (!mapgenerate(init, argv[1]))
		return (0);
	init->win = mlx_new_window(init->mlx, SCREEN_WIDTH, SCREEN_HEIGH,
			"cub3dbonus");
	if (!((init)->win))
		return (0);
	init_event(init);
	if (!initialize_player(init))
		return (0);
	if (!initialize_image(init))
		return (0);
	mlx_hook(init->win, ON_KEYUP, 1L << 1, keyup, init);
	mlx_hook(init->win, ON_DESTROY, 1L << 0, finish, init);
	mlx_hook(init->win, ON_KEYDOWN, 1L << 0, keydown, init);
	mlx_hook(init->win, ON_MOUSEMOVE, 1L<<6, mousemove, init);
	mlx_loop_hook(init->mlx, basic_loop, init);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	getscreen(init);
	return (1);
}
