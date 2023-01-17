/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/17 03:04:58 by aeryilma         ###   ########.fr       */
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
		tmp = get_next_line(fd);
		if (tmp && (*ylen) < ft_strlen(tmp))
			(*ylen) = ft_strlen(tmp);
		(*xlen)++;
	}
	close(fd);
	return (1);
}

char	**getmap(char *file, int ylen)
{
	int		fd;
	int		i;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	map = (char *)malloc(sizeof(char *) * ylen);
	i = 0;
	while (++i < 9)
		free(get_next_line(fd));
	i = 0;
	while (--ylen > 0)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = 0;
	return (map);
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


//* test
	int i = -1;
	while(game->map[++i])
	{
		printf("%s", game->map[i]);
	}
	return (1);
}
