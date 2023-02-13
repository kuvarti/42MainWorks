/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importxmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:25:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/30 20:47:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load(int i, t_cub3d *game, char *line)
{
	int		size;
	char	*sprite;
	t_data	*tmp;

	size = 64;
	game->texture.xpm[i] = malloc(sizeof(t_data));
	tmp = game->texture.xpm[i];
	sprite = ft_strndup(&line[3], ft_strlen(&line[3]) - 1);
	tmp->img = mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
	tmp->addr = mlx_get_data_addr(tmp->img,
			&(tmp->bits_per_pixel), &(tmp->line_length), &(tmp->endian));
	if (!(tmp->img) || !(tmp->addr))
		return (0);
	if (sprite)
		free(sprite);
	return (1);
}

//* 0xffffff == 255, 255, 255 == 16777215
static int	getcolor(t_cub3d *game, char *line)
{
	char	**rgb;
	int		color;

	rgb = 0;
	rgb = ft_split(line, ',');
	color = \
	(ft_atoi(&rgb[0][2]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
	if (!ft_strncmp(line, "F ", 2))
		game->texture.bot = color;
	else
		game->texture.top = color;
	color = 0;
	while (rgb[color])
		free(rgb[color++]);
	free(rgb);
	return (0);
}

int	importxpm(t_cub3d *game, char *line)
{
	if (!ft_strncmp(line, "\n", 1))
		return (0);
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (!load(0, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (!load(1, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (!load(2, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (!load(3, game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (getcolor(game, line));
	return (0);
}
