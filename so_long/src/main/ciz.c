/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:52:08 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/15 01:34:39 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	spriteciz(void *img, const t_game *oyun, int x, int y)
{
	mlx_put_image_to_window(oyun->mlx, oyun->win, img, 45 * x, 45 * y);
}

void	spritedoldur(t_game *oyun)
{
	int		sprlen;

	ft_printf("prites loading..");
	sprlen = 45;
	oyun->sprite.gemi = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/gemi1.xpm", &sprlen, &sprlen);
	oyun->sprite.zemin = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/template.xpm", &sprlen, &sprlen);
	oyun->sprite.duvar = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/wall.xpm", &sprlen, &sprlen);
	oyun->sprite.havlu = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/havlu1.xpm", &sprlen, &sprlen);
	oyun->sprite.dusman = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/dusman.xpm", &sprlen, &sprlen);
	oyun->sprite.karakter = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/character1.xpm", &sprlen, &sprlen);
	oyun->sprite.rkarakter = mlx_xpm_file_to_image(oyun->mlx,
		"./sprites/rcharacter1.xpm", &sprlen, &sprlen);
}

void	mapciz(t_game *oyun)
{
	int			x;
	int			y;

	y = -1;
	mlx_clear_window(oyun->mlx, oyun->win);
	while (oyun->map[++y])
	{
		x = -1;
		while (oyun->map[y][++x])
		{
			spriteciz(oyun->sprite.zemin, oyun, x, y);
			if (oyun->map[y][x] == '1')
				spriteciz(oyun->sprite.duvar, oyun, x, y);
			else if (oyun->map[y][x] == 'C')
				spriteciz(oyun->sprite.havlu, oyun, x, y);
			else if (oyun->map[y][x] == 'E')
				spriteciz(oyun->sprite.gemi, oyun, x, y);
			else if (oyun->map[y][x] == 'P')
			{
				if (oyun->yon == SAG)
					spriteciz(oyun->sprite.karakter, oyun, x, y);
				else
					spriteciz(oyun->sprite.rkarakter, oyun, x, y);
			}
		}
	}
}
