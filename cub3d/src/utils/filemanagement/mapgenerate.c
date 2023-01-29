/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/29 04:59:04 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_mapspaces(char **map, int xlen)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
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

int	loadsprites(int fd, t_cub3d *game)
{
	char	*line;

	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (importxpm(game, line))
			return (0);
		free(line);
		if (game->texture.xpm[0] && game->texture.xpm[1] && game->texture.xpm[2]
				&& game->texture.xpm[3] && game->texture.bot && game->texture.top)
			break ;
	}
	return (1);
}

int	mapgenerate(t_cub3d *game, char *file)
{
	int	fd;

	game->map = malloc(sizeof(t_map));
	if (ft_strlen(file) < 5 || ft_strrcmp(file, ".cub") != 0)
		return (!printf("Wrong file format: correct file format: file.cub\n"));

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (!printf("File Not Found :%s\n", file));
	if (!loadsprites(fd, game))
		return(0);

	game->map->map = getmap(file);
	if (!game->map)
		return (!printf("Some Error Accuired.\n"));
	if (!fill_mapspaces(game->map->map, game->map->y))
		return (!printf("Unsupported character detected.\n"));
	if (!mapcheck(game->map->map))
		return (!printf("Map & Player must be covered by wall(s)\n"));
	close(fd);
	return (1);
}
