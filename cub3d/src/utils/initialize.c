/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:40:03 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 23:57:58 by aeryilma         ###   ########.fr       */
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

void drawline(t_cub3d *game, t_vectord p1, t_vectord p2)
{
	float x = p2.X - p1.X;
	float y = p2.Y - p1.Y;

	const float max = x < y ? x : y;
	x /= max;
	y /= max;
	for (float n = 0; n < max; ++n)
	{
		my_mlx_pixel_put(&(game->img), (game->player->pos.Y * 100) + 50+ p1.X, (game->player->pos.Y * 100) + 50 + p1.Y, 0x00FF00);
		p1.X += x;
		p1.Y += y;
	}
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

void	raycast(t_cub3d *game)
{
	int		r, mx, my, mp, dof;
	float	rx, ry, ra, xo, yo;

	ra = game->player->angle;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1/tan(ra);
		//looking down
		if (ra > PI)
		{
			ry = (((int)game->player->pos.Y >>6) <<  6) - 0.0001;
			rx = (game->player->pos.Y - ry) * aTan + game->player->pos.X;
			yo = -64;
			xo = -yo * aTan;
		}
		else if (ra < PI)
		{
			ry = (((int)game->player->pos.Y >>6) <<  6) + 64;
			rx = (game->player->pos.Y - ry) * aTan + game->player->pos.X;
			yo = 64;
			xo = yo * aTan;
		}
		else if (ra == 0 || ra == PI)
		{
			rx = game->player->pos.X;
			ry = game->player->pos.Y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx >> 6;
			my = (int)(ry) >> 6;
			mp = my * game->map->x + mx;
			if ( mp < game->map->x * game->map->y && game->map->map[mp] == '1')
				dof = 8;
			else
			{
				rx+= xo;
				ry += yo;
				dof += 1;
			}
		}
		t_vectord a;
		a.X = rx;
		a.Y = ry;
		drawline(game, game->player->pos, a );
	}
}

void	ciz(t_cub3d *game)
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
