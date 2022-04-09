/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveevents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:08:26 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/07 14:25:02 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "fl_mngmnt.h"

int	girdial(int keycode, t_game *oyun)
{
	if (keycode == KEY_ESC || keycode == 65307)
	{
		mlx_destroy_window(oyun->mlx, oyun->win);
		exit(ft_printf("\nOyun Bitti,\nByee..\n"));
		return (0);
	}
	if (oyun->durum == 1)
	{
		if (keycode == KEY_W || keycode == KEY_UP || keycode == 119)
			git(oyun, 0, -1);
		if (keycode == KEY_S || keycode == KEY_DOWN || keycode == 115)
			git(oyun, 0, 1);
		if (keycode == KEY_D || keycode == KEY_RIGHT || keycode == 100)
			git(oyun, 1, 0);
		if (keycode == KEY_A || keycode == KEY_LEFT || keycode == 97)
			git(oyun, -1, 0);
		ft_printf("\r");
		ft_printf("Haraket Sayisi: %d", oyun->haraket_sayisi);
		mapciz(oyun);
	}
	return (keycode);
}

static void	swapmod(char *e, char *n, t_game *oyun, char mod)
{
	if (mod == 'S')
	{
		*e ^= *n;
		*n ^= *e;
		*e ^= *n;
	}
	if (mod == SAG)
		oyun->yon = SAG;
	if (mod == SOL)
		oyun->yon = SOL;
}

void	oyunubitir(t_game *oyun)
{
	oyun->durum = !1;
	mlx_clear_window(oyun->mlx, oyun->win);
}

void	git(t_game *oyun, int x, int y)
{
	char	*e;
	char	*n;

	e = &(oyun->map[oyun->pos.y][oyun->pos.x]);
	n = &(oyun->map[oyun->pos.y + y][oyun->pos.x + x]);
	(oyun->haraket_sayisi)++;
	if ('1' == *n)
		return ;
	else if ('E' == *n)
	{
		if (oyun->coincount == 0)
			oyunubitir(oyun);
		return ;
	}
	else if ('C' == *n && (oyun->coincount)--)
		*n = '0';
	swapmod(e, n, oyun, 'S');
	oyun->pos.y += y;
	oyun->pos.x += x;
	if (x == 1)
		oyun->yon = SAG;
	if (x == -1)
		oyun->yon = SOL;
}
