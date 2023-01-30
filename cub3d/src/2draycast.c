/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:37:41 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/30 21:08:28 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void raycast(t_cub3d *game);

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

void	drawline(t_cub3d *game, t_vectord start, t_vectord end, int color)
{
    int dx = end.x - (start.x * 100 + 50);
    int dy = end.y - (start.y * 100 + 50);
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    float X = start.x * 100 + 50;
    float Y = start.y * 100 + 50;
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

	if (color == 0)
	{
		_x = x * 100;
		_x -=50;
		i = _x + 100;
		while (_x < i)
		{
			_y = y * 100;
			_y -=50;
			j = _y + 100;
			while (_y < j)
			{
				my_mlx_pixel_put(game->img, _x + 50, _y + 50, color);
				_y++;
			}
			_x++;
		}
		return ;
	}
}

void	ciz(t_cub3d *game)
{
	mlx_clear_window(game->mlx, game->win);
	raycast(game);
//	printf("(player.x,player.y) : %0.2f %0.2f\n(dir.x, dir.y) : %0.2f %0.2f\n(plane.x, plane.y) %0.2f %0.2f \n\n",
//			game->player->pos.x, game->player->pos.y,
//			game->player->dir.x, game->player->dir.y,
//			game->player->plane.x, game->player->plane.y);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture.xpm[0]->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture.xpm[1]->img, 64, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture.xpm[2]->img, 128, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->texture.xpm[3]->img, 192, 0);
}

void	verline(t_cub3d *game, int x, int ystart, int yend, char *color)
{
	int	i;

	i = 0;
	while (i <= SCREEN_HEIGH)
	{
		if (i >= yend)
			my_mlx_pixel_put(game->img, x, i, game->texture.bot);
		else if (i >= ystart && i <= yend)
		{
			my_mlx_pixel_put(game->img, x, i, color);
		}
		else
			my_mlx_pixel_put(game->img, x, i, game->texture.top);
		i++;
	}
}

void	raycast(t_cub3d *game)
{
	double	posX = game->player->pos.x, posY = game->player->pos.y;  //x and y start position
	double	dirX = game->player->dir.x,
			dirY = game->player->dir.y;
	double	planeX = game->player->plane.x,
			planeY = game->player->plane.y; //the 2d raycaster version of camera plane

	for(int x = 0; x < SCREEN_WIDTH; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)(posX);
		int mapY = (int)(posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		//these are derived as:
		//deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		//deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		//which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
		//where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		//unlike (dirX, dirY) is not 1, however this does not matter, only the
		//ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		//stepping further below works. So the values can be computed as below.
		// Division through zero is prevented, even though technically that's not
		// needed in C++ with IEEE 754 floating point values.
		double deltaDistX = (rayDirX == 0) ? 1e30 : dabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : dabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(!game->map->map[mapY])
				break ;
			else if (game->map->map[mapY][mapX] == '1')
				hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGH/ perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGH / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGH / 2;
		if(drawEnd >= SCREEN_HEIGH) drawEnd = SCREEN_HEIGH - 1;

		//choose wall color
		int color = 0xffffff;

		int pitch = 100;

		// side 1 ise N S
		// side 0 ise W E
		double wallX;
		int	wall;
		//give x and y sides different brightness
		if (side == 0)
		{
			wallX = game->player->pos.y + perpWallDist * rayDirY;
			if (mapX < game->player->pos.x)
				color = 0xff0000; //E
			else
				color = 0x00ff00; //W
		}
		else
		{
			wallX = game->player->pos.x + perpWallDist * rayDirX;
			if (mapY < game->player->pos.y)
				color = 0x0000ff; //S
			else
				color = 0x0ffff0; //N
		}
		//wallX -= floor(wallX);	//todo
//
		//int	texX = (int)(wallX * (double)(64));
		//if (side == 0 && rayDirX > 0)
		//	texX = 64 - texX - 1;
		//if (side == 1 && rayDirY < 0)
		//	texX = 64 - texX - 1;
		////draw the pixels of the stripe as a vertical line
//
		//double step = 1.0 * 64 / lineHeight;
		//double texPos = (drawStart - pitch - SCREEN_HEIGH / 2 + lineHeight / 2) * step;
		//for (int y = drawStart; y < drawEnd; y++)
		//{
		//	int texY = (int)texPos & (64 - 1);
		//	texPos += step;
		//	color = (game->texture.xpm[wall][1]);
		//	my_mlx_pixel_put(game->img, x, y, color);
		//}


		verline(game, x, drawStart, drawEnd, color);
	}
}
