/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusanimations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 22:33:30 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/14 23:39:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "solong.h"

static void	devpos(t_game *oyun, int x, int y)
{
	char	*e;
	int		i;

	e = &(oyun->map[y][x]);
	if (oyun->map[y][x + 1] == 'P')
		bitir(oyun, "\nDusmana dokunmamalısın!!\n");
	else if (ft_strchr("0", oyun->map[y][x + 1]))
		swapmod(e, &(oyun->map[y][x + 1]), oyun, 'S');
	else
	{
		i = 0;
		while (ft_strchr("0PD", oyun->map[y][x - i]))
			i++;
		if ((oyun->map[y][x - i + 1]) == 'P')
			bitir(oyun, "\nDusmana dokunmamalısın!!\n");
		swapmod(e, &(oyun->map[y][x - i + 1]), oyun, 'S');
	}
}

void	devriye(t_game *oyun)
{
	int	x;
	int	y;

	y = 0;
	while (oyun->map[y])
	{
		x = 0;
		while (oyun->map[y][x])
		{
			if (oyun->map[y][x] == 'D')
			{
				devpos(oyun, x, y);
				x++;
			}
			x++;
		}
		y++;
	}
}

void	havluanim(t_game *oyun, int x, int y)
{
	int sprlen;

	sprlen = 45;
	if (oyun->animtime / 4 == 0)
		spriteciz(oyun->sprite.havlu, oyun, x, y);
	else if (oyun->animtime / 4 == 1)
		spriteciz(oyun->sprite.havlu1, oyun, x, y);
	else if (oyun->animtime / 4 == 2)
		spriteciz(oyun->sprite.havlu2, oyun, x, y);
	else if (oyun->animtime / 4 == 3)
		spriteciz(oyun->sprite.havlu3, oyun, x, y);
	else
	{
		oyun->animtime = 0;
		spriteciz(oyun->sprite.havlu, oyun, x, y);
	}
}
