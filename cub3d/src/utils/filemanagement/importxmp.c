/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importxmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 01:25:43 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/29 04:53:50 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load(void	**xpm, t_cub3d *game, char *line)
{
	int		size;
	char	*sprite;

	size = 64;
	sprite = ft_strndup(&line[3], ft_strlen(&line[3]) - 1);
	*xpm = \
	mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
	if (sprite)
		free(sprite);
	if (!(*xpm))
		return (0);
	return (1);
}

//* 0xffffff == 255, 255, 255 == 16777215

static int	getcolor(t_cub3d *game, char *line)
{
	char	**rgb;
	int		color;

	rgb = 0;
	rgb = ft_split(line, ',');
	color = (ft_atoi(&rgb[0][2]) << 16 | ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
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
		if (!load(&(game->texture.xpm[0]), game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (!load(&(game->texture.xpm[1]), game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (!load(&(game->texture.xpm[2]), game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (!load(&(game->texture.xpm[3]), game, line))
			return (printf("File Not Found :%s\n", &line[3]));
	}
	else if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return(getcolor(game, line));
	return (0);
}
