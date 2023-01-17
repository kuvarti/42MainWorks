/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/18 02:41:07 by aeryilma         ###   ########.fr       */
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
	while(tmp)
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
				return(0);
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

int	mapcheck(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if(map[i][j] != '0')
				continue ;
			else if (!ft_strchr("1NSEW", map[i + 1][j]))
				return (0);
			else if (!ft_strchr("1NSEW", map[i - 1][j]))
				return (0);
			else if (!ft_strchr("1NSEW", map[i][j - 1]))
				return (0);
			else if (!ft_strchr("1NSEW", map[i][j + 1]))
				return (0);
		}
	}
	return (1);
}

int	mapgenerate(t_cub3d *game, char *file)
{
	size_t	xlen;
	size_t	ylen;

	if (ft_strlen(file) < 5 || ft_strrcmp(file, ".cub") != 0)
		return (!printf("Wrong file format: correct file format: file.cub\n"));
	if (!maplens(&ylen, &xlen, file))
		return (!printf("File Not Found :%s\n", file));
	game->map = getmap(file, ylen);
	if (!game->map)
		return(!printf("Some Error Accuired.\n"));
	if (!fill_mapspaces(game->map, xlen))
		return(!printf("Unsupported character detected.\n"));
	if (!mapcheck(game->map))
		return(!printf("Map must be covered by wall(s)\n"));
	return (1);
}
