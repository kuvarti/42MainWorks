/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusoyunubaslat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:35:38 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/15 01:36:10 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "events.h"
#include "limits.h"

int	windowlen(char **map, char mod)
{
	int	i;

	i = 1;
	if (mod == 'y')
	{
		while (map[i])
			i++;
		return (i * 45);
	}
	if (mod == 'x')
	{
		while (map[0][i])
			i++;
		return (i * 45);
	}
	return (0);
}

int	bitir(t_game *oyun, char *msg)
{
	int	x;

	x = 0;
	while (oyun->map[x])
		free(oyun->map[x++]);
	free(oyun->sprite.zemin);
	free(oyun->sprite.karakter);
	free(oyun->sprite.rkarakter);
	free(oyun->sprite.dusman);
	free(oyun->sprite.gemi);
	free(oyun->sprite.havlu);
	free(oyun->sprite.havlu1);
	free(oyun->sprite.havlu2);
	free(oyun->sprite.havlu3);
	free(oyun->sprite.duvar);
	ft_printf("%s", msg);
	exit(mlx_destroy_window(oyun->mlx, oyun->win));
	return (1);
}

int	deneme(t_game *oyun)
{
	(oyun->animtime)++;
	if (oyun->durum != 2)
		mapciz(oyun);
	if (oyun->animtime / 4 > 3)
		oyun->animtime = 0;
	if (oyun->animtime / 5 == 3)
		devriye(oyun);
	return (1);
}

void	baslat(t_game *oyun)
{
	oyun -> animtime = 0;
	oyun -> yon = SAG;
	oyun -> haraket_sayisi = 0;
	oyun -> durum = 1;
	oyun->mlx = mlx_init();
	ft_printf("Oyun Basliyor, \n");
	spritedoldur(oyun);
	if (oyun->sprite.duvar)
		ft_printf("Done\n\n");
	oyun->win = mlx_new_window(oyun->mlx, windowlen(oyun->map, 'x'),
			windowlen(oyun->map, 'y') + 12, "so_long-bonus");
	mapciz(oyun);
	mlx_loop_hook(oyun->mlx, deneme, oyun);
	mlx_hook(oyun->win, ON_KEYDOWN, 1L << 0, girdial, oyun);
	mlx_hook(oyun->win, ON_DESTROY, 1L << 0, bitir, oyun);
	ft_printf("Haraket Sayısı: %d", oyun->haraket_sayisi);
	mlx_loop(oyun->mlx);
}
