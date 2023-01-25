/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/25 03:58:53 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > SCREEN_HEIGH)
		return ;
	if (x < 0 || x > SCREEN_WIDTH)
		return ;
	dst = \
	data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	drawline(t_cub3d *game, t_vectord start, t_vectord end, int color)
{
    int dx = end.X - (start.X * 100 + 50);
    int dy = end.Y - (start.Y * 100 + 50);
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = start.X * 100 + 50;
    float Y = start.Y * 100 + 50;
    for (int i = 0; i <= steps; i++)
    {
		my_mlx_pixel_put(game->img, X, Y, color);
        X += Xinc;
        Y += Yinc;
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
			my_mlx_pixel_put(game->img, _x + 50, _y + 50, color);
			_y++;
		}
		_x++;
	}
}

void	simpleraycasat(t_cub3d *game)
{
	//0,0 distance
	double x0 = game->player->pos.X, y0 = game->player->pos.Y;
    // Işının hızı (v) ve yönü (angle)
    //double v = 1;
	double angle = game->player->angle;
    // Işının çarpışma noktası (x1, y1)
    double x1, y1;
    // Işının çarpışma noktasına kadar olan mesafe (d)
    double d;

    // Işının yönünü radyana çeviriyoruz
    angle = angle * PI / 180;
    // Işının çarpışma noktasını hesaplıyoruz
    d = sqrt(x0*x0 + y0*y0);
    x1 = x0 + d * cos(angle);
    y1 = y0 + d * sin(angle);

    printf("(x1, y1) = (%f, %f)\n", x1, y1);
}

void drawplayer(t_cub3d *game)
{
	drawsquare(game, game->player->pos.X, game->player->pos.Y, 0x440088);
	my_mlx_pixel_put(game->img,
		(game->player->pos.X * 100) + 50 + game->player->delta.X * 7,
		(game->player->pos.Y * 100) + 50 + game->player->delta.Y * 7,
		0xFFFFFF);
}

void raycast(t_cub3d *game);

void	ciz(t_cub3d *game)
{
	mlx_clear_window(game->mlx, game->win);
	int i = -1;
	int j;

	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (game->map->map[i][j] == '1')
				drawsquare(game, j, i, 0xFFFFFF);
			else
				drawsquare(game, j, i, 0x000000);
		}
	}
	drawplayer(game);
	//raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}

/*
#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64      //map cube size
int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,
};

void raycast(t_cub3d *game)
{
	int r, mx,my,mp,dof; double rx, ry, ra, xo, yo;
	ra = game->player->angle;

	for (r = 0; r < 1; r++)
	{
		dof = 0;
		double aTan = -1/tan(ra);
		if (ra > PI) //looking down
		{
			ry = (((int)game->player->pos.Y >>6)<<6) - 0.0001;
			rx = (game->player->pos.Y  - ry) * aTan+game->player->pos.X;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < PI) //looking up
		{
			ry = (((int)game->player->pos.Y >>6)<<6) + 64;
			rx = (game->player->pos.Y  - ry) * aTan+game->player->pos.X;
			yo = 64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = game->player->pos.X;
			ry = game->player->pos.Y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * mapX + mx;
			if (mp < mapX * mapY && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof+= 1;
			}
		}
		t_vectord a;
		a.X = rx * 100 + 50;	a.Y = ry * 100 + 50;
		drawline(game, game->player->pos, a, 0x00ff00);
		printf("player: %0.2f,%0.2f\n ray %0.2f,%0.2f\n",
			game->player->pos.X * 100 + 50,
			game->player->pos.Y * 100 + 50,
			rx * 100 + 50,
			ry * 100 + 50
		);
	}
}

*/
