/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusciz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:37:05 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/12 23:48:34 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	spriteciz(const char *sprite, const t_game *oyun, int x, int y)
{
	void	*img;
	int		sprlen;

	sprlen = 45;
	img = mlx_xpm_file_to_image(oyun->mlx, (char *)sprite, &sprlen, &sprlen);
	mlx_put_image_to_window(oyun->mlx, oyun->win, img, 45 * x, 45 * y);
}

static void	spritedoldur(t_sprites *sprite, const t_game *oyun)
{
	sprite->sprlen = 45;
	sprite->gemi = "./sprites/gemi1.xpm";
	sprite->zemin = "./sprites/template.xpm";
	sprite->duvar = "./sprites/wall.xpm";
	sprite->havlu = "./sprites/havlu1.xpm";
	sprite->dusman = "./sprites/dusman.xpm";
	if (oyun->yon == SAG)
		sprite->karakter = "./sprites/character1.xpm";
	else
		sprite->karakter = "./sprites/rcharacter1.xpm";
}

void	havluanim(t_game *oyun, int x, int y)
{
	if (oyun->animtime / 4 == 0)
		spriteciz("./sprites/havlu1.xpm", oyun, x, y);
	else if (oyun->animtime / 4 == 1)
		spriteciz("./sprites/havlu2.xpm", oyun, x, y);
	else if (oyun->animtime / 4 == 2)
		spriteciz("./sprites/havlu3.xpm", oyun, x, y);
	else if (oyun->animtime / 4 == 3)
		spriteciz("./sprites/havlu4.xpm", oyun, x, y);
	else
	{
		oyun->animtime = 0;
		spriteciz("./sprites/havlu1.xpm", oyun, x, y);
	}
}

static void	mapciz1(t_game *oyun)
{
	int			x;
	int			y;
	t_sprites	sprite;

	spritedoldur(&sprite, oyun);
	y = -1;
	mlx_clear_window(oyun->mlx, oyun->win);
	while (oyun->map[++y])
	{
		x = -1;
		while (oyun->map[y][++x])
		{
			spriteciz(sprite.zemin, oyun, x, y);
			if (oyun->map[y][x] == '1')
				spriteciz(sprite.duvar, oyun, x, y);
			else if (oyun->map[y][x] == 'C')
				havluanim(oyun, x, y);
			else if (oyun->map[y][x] == 'E')
				spriteciz(sprite.gemi, oyun, x, y);
			else if (oyun->map[y][x] == 'P')
				spriteciz(sprite.karakter, oyun, x, y);
			else if (oyun->map[y][x] == 'D')
				spriteciz(sprite.dusman, oyun, x, y);
		}
	}
}

void	mapciz(t_game *oyun)
{
	mapciz1(oyun);
	mlx_string_put(oyun->mlx, oyun->win, 5, 10 + windowlen(oyun->map, 'y'),
		0xFFFFFF, ft_strjoin("Haraket Sayisi: ",
			ft_itoa(oyun->haraket_sayisi)));
}
