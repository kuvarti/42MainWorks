/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveevents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:08:26 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/15 00:47:34 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "fl_mngmnt.h"

int	girdial(int keycode, t_game *oyun)
{
	if (keycode == KEY_ESC)
		bitir(oyun, "\nbyee\n");
	if (oyun->durum == 1)
	{
		if (keycode == KEY_W || keycode == KEY_UP)
			git(oyun, 0, -1);
		else if (keycode == KEY_S || keycode == KEY_DOWN)
			git(oyun, 0, 1);
		else if (keycode == KEY_D || keycode == KEY_RIGHT)
			git(oyun, 1, 0);
		else if (keycode == KEY_A || keycode == KEY_LEFT)
			git(oyun, -1, 0);
		ft_printf("\r");
		mapciz(oyun);
		ft_printf("Haraket Sayısı: %d", oyun->haraket_sayisi);
	}
	return (keycode);
}

void	swapmod(char *e, char *n, t_game *oyun, char mod)
{
	if (mod == 'S')
	{
		*e ^= *n;
		*n ^= *e;
		*e ^= *n;
		return ;
	}
	if (mod == SAG)
		oyun->yon = SAG;
	else if (mod == SOL)
		oyun->yon = SOL;
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
			bitir(oyun, "\nTebrikler\n");
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
