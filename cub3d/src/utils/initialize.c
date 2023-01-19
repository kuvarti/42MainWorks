/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 23:18:51 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	getplayerdir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->angle = (3 * PI) / 2;
		game->player->delta.X = cos(game->player->angle) * 5;
		game->player->delta.Y = sin(game->player->angle) * 5;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	drawsquare(t_cub3d *game, double x, double y, int color)
{
	int	_x;
	int	_y;
	int	i;
	int	j;

	_x = x * 100;
	_x -=50;
	i = _x + 99;
	while (_x < i)
	{
		_y = y * 100;
		_y -=50;
		j = _y + 99;
		while (_y < j)
		{
			my_mlx_pixel_put(&(game->img), _x + 50, _y + 50, color);
			_y++;
		}
		_x++;
	}
}

void ciz(t_cub3d *game)
{
	mlx_clear_window(game->mlx, game->win);
	int i = -1;
	int j;

	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGH);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
								&game->img.line_length, &game->img.endian);
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (game->map->map[i][j] == '1')
				drawsquare(game, j, i, 0xFFFFFF);
		}
	}
	drawsquare(game, game->player->pos.X, game->player->pos.Y, 0x440088);
	my_mlx_pixel_put(&(game->img), (game->player->pos.X * 100) + 50 + game->player->delta.X * 7,
		(game->player->pos.Y * 100) + 50 + game->player->delta.Y * 7, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
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
	if (!initialize_player(init))
		return (0);
	mlx_hook(init->win, ON_DESTROY, 1L << 0, finish, init);
	mlx_hook(init->win, ON_KEYDOWN, 1L << 0, getkeys, init);
	return (1);
}
