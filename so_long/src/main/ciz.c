/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ciz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:52:08 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/07 08:24:06 by aeryilma         ###   ########.fr       */
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
	if (oyun->yon == SAG)
		sprite->karakter = "./sprites/character1.xpm";
	else
		sprite->karakter = "./sprites/rcharacter1.xpm";
}

void	mapciz(const t_game *oyun)
{
	int			x;
	int			y;
	t_sprites	sprite;

	spritedoldur(&sprite, oyun);
	y = 0;
	mlx_clear_window(oyun->mlx, oyun->win);
	while (oyun->map[y])
	{
		x = 0;
		while (oyun->map[y][x])
		{
			spriteciz(sprite.zemin, oyun, x, y);
			if (oyun->map[y][x] == '1')
				spriteciz(sprite.duvar, oyun, x, y);
			else if (oyun->map[y][x] == 'C')
				spriteciz(sprite.havlu, oyun, x, y);
			else if (oyun->map[y][x] == 'E')
				spriteciz(sprite.gemi, oyun, x, y);
			else if (oyun->map[y][x] == 'P')
				spriteciz(sprite.karakter, oyun, x, y);
					x++;
		}
		y++;
	}
}
