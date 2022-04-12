/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonusoyunubaslat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:35:38 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/12 23:49:11 by aeryilma         ###   ########.fr       */
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

int	bitir(t_game *oyun)
{
	exit(mlx_destroy_window(oyun->mlx, oyun->win));
	return (1);
}

int	deneme(t_game *oyun)
{
	(oyun->animtime)++;
	if (oyun->durum != 2)
		mapciz(oyun);
	return (1);
}

void	baslat(t_game *oyun)
{
	oyun -> animtime = 0;
	oyun -> yon = SAG;
	oyun -> haraket_sayisi = 0;
	oyun -> durum = 1;
	oyun->mlx = mlx_init();
	ft_printf("Oyun Basliyor, \n\n");
	oyun->win = mlx_new_window(oyun->mlx, windowlen(oyun->map, 'x'),
			windowlen(oyun->map, 'y') + 12, "so_long");
	mapciz(oyun);
	mlx_loop_hook(oyun->mlx, deneme, oyun);
	mlx_hook(oyun->win, ON_KEYDOWN, 1L << 0, girdial, oyun);
	mlx_hook(oyun->win, ON_DESTROY, 1L << 0, bitir, oyun);
	ft_printf("Haraket Sayısı: %d", oyun->haraket_sayisi);
	mlx_loop(oyun->mlx);
}
