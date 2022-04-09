/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:32:39 by aeryilma          #+#    #+#             */
/*   Updated: 2022/03/30 14:38:37 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fl_mngmnt.h"
#include "ft_printf.h"
#include <assert.h>

static char	map_ol_control(char **map, int *i, int *j)
{
	*i = 0;
	while (map[0][*i])
	{
		if ('1' != map[0][(*i)++])
			return (0);
	}
	*j = 0;
	while (map[*j])
	{
		if ('1' != map[*j][0] || '1' != map[*j][*i - 1])
			return (0);
		(*j)++;
	}
	*i = 0;
	while (map[*j - 1][*i])
	{
		if ('1' != map[*j - 1][(*i)++])
			return (0);
	}
	return (1);
}

static void	map_min_spec(char c, t_mapcheck *test, char mod)
{
	if (mod == 1)
	{
		test->c = 0;
		test->e = 0;
		test->p = 0;
		return ;
	}
	if (c == 'C')
		test->c++;
	else if (c == 'E')
		test->e++;
	else if (c == 'P')
		test->p++;
}

static void	oyuncubul(t_game *oyun, t_mapcheck mapc)
{
	int	xx;
	int	yy;

	yy = 0;
	oyun->coincount = mapc.c;
	while (oyun->map[yy])
	{
		xx = 0;
		while (oyun->map[yy][xx])
		{
			if (oyun->map[yy][xx] == 'P')
			{
				oyun->pos.x = xx;
				oyun->pos.y = yy;
				return ;
			}
			xx++;
		}
		yy++;
	}
}

char	mapcontrol(t_game *oyun)
{
	t_mapcheck	*test;
	int			i_max;
	int			j_max;

	if (!map_ol_control(oyun->map, &i_max, &j_max))
		return (0);
	test = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	map_min_spec(0, test, 1);
	test -> j = -1;
	while (++(test -> j) < j_max)
	{
		test -> i = -1;
		while (++(test -> i) < i_max)
		{
			if (!ft_strchr("01CEP", oyun->map[test -> j][test -> i]))
				return (0);
			map_min_spec(oyun->map[test -> j][test -> i], test, 0);
		}
	}
	if (test -> c < 1 || test -> e < 1 || test -> p < 1)
		return (0);
	oyuncubul(oyun, *test);
	free(test);
	return (1);
}
