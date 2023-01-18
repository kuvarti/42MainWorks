/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 00:52:27 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	maplens(size_t *xlen, size_t *ylen, char *file)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (++i < 9)
		free(get_next_line(fd));
	*xlen = 1;
	tmp = get_next_line(fd);
	*ylen = ft_strlen(tmp);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp && (*ylen) < ft_strlen(tmp))
			(*ylen) = ft_strlen(tmp);
		(*xlen)++;
	}
	close(fd);
	return (1);
}

int	fill_mapspaces(char **map, int xlen)
{
	int		i;
	int		j;
	int		flag;
	char	*tmp;

	i = -1;
	flag = 0;
	while(map[++i])
	{
		tmp = malloc(xlen - 1);
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\n')
				break ;
			if (!ft_strchr("10NSE W", map[i][j]))
				return (0);
			tmp[j] = map[i][j];
		}
		if (map[i][j])
			tmp[j] = ' ';
		while (++j < xlen)
			tmp[j] = ' ';
		tmp[j] = 0;
		free(map[i]);
		map[i] = tmp;
	}
	return (1);
}

char	**getmap(char *file, size_t ylen)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = (char **)malloc(sizeof(char *) * ylen);
	i = 0;
	while (++i < 9)
		free(get_next_line(fd));
	i = 0;
	while (--ylen > 0)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	return (map);
}

int	mapgenerate(t_cub3d *game, char *file)
{
	game->map = malloc(sizeof(t_map));
	if (ft_strlen(file) < 5 || ft_strrcmp(file, ".cub") != 0)
		return (!printf("Wrong file format: correct file format: file.cub\n"));
	if (!maplens(&game->map->y, &game->map->x, file))
		return (!printf("File Not Found :%s\n", file));
	game->map->map = getmap(file, game->map->y);
	if (!game->map)
		return (!printf("Some Error Accuired.\n"));
	if (!fill_mapspaces(game->map->map, game->map->y))
		return (!printf("Unsupported character detected.\n"));
	if (!mapcheck(game->map->map))
		return (!printf("Map & Player must be covered by wall(s)\n"));
	return (1);
}
