/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/24 20:51:25 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_mapspaces(char **map, int xlen, int i)
{
	int		j;
	char	*tmp;

	while (map[++i])
	{
		tmp = ft_calloc(xlen + 1, 1);
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("10NSE W", map[i][j]))
				return (0);
			tmp[j] = map[i][j];
		}
		while (++j < xlen)
			tmp = ft_gnl_strjoin(tmp, " ");
		free(map[i]);
		map[i] = tmp;
	}
	return (1);
}

char	*getmaptext(int fd)
{
	char	*str;
	char	*check;

	check = 0;
	while (1)
	{
		if (check)
			free(check);
		check = get_next_line(fd);
		if (ft_strncmp(check, "\n", 1))
			break ;
	}
	str = 0;
	while (1)
	{
		str = ft_gnl_strjoin(str, check);
		free(check);
		check = get_next_line(fd);
		if (!check)
			break ;
	}
	return (str);
}

char	**getmap(t_cub3d *game, int fd)
{
	size_t	tmp;
	char	**map;
	char	*text;
	char	*check;

	text = getmaptext(fd);
	check = ft_strnstr(text, "\n\n", ft_strlen(text));
	if (check)
		return (0);
	map = ft_split(text, '\n');
	free(text);
	game->map->y = 0;
	game->map->x = 0;
	while (map[game->map->y])
	{
		tmp = ft_strlen(map[game->map->y]);
		if (game->map->x < tmp)
			game->map->x = tmp + 1;
		game->map->y++;
	}
	return (map);
}

int	loadsprites(int fd, t_cub3d *game)
{
	char	*line;
	int		ret;

	ret = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		ret++;
		if (importxpm(game, line))
			return (0);
		free(line);
		if (game->texture.bot && game->texture.top)
			break ;
	}
	return (ret);
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
		return (!printf("Some Error Accuired!\n"));
	game->map->map = getmap(game, fd);
	if (!game->map->map)
		return (!printf("Some Error Accuired.\n"));
	if (!fill_mapspaces(game->map->map, game->map->x, -1))
		return (!printf("Unsupported character detected.\n"));
	if (!mapcheck(game->map->map))
		return (!printf("Map & Player must be covered by wall(s)\n"));
	close(fd);
	return (1);
}
