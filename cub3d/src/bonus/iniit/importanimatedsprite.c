/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importanimatedsprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 04:42:42 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/15 05:18:11 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	spriteload(int i, t_cub3d *game, char *line)
{
	int		size;
	char	*sprite;
	t_data	*tmp;

	size = 64;
	game->texture.sprite[i] = malloc(sizeof(t_data));
	tmp = game->texture.sprite[i];
	sprite = ft_strndup(&line[4], ft_strlen(&line[4]) - 1);
	tmp->img = mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
	tmp->addr = mlx_get_data_addr(tmp->img,
			&(tmp->bits_per_pixel), &(tmp->line_length), &(tmp->endian));
	if (!(tmp->img) || !(tmp->addr))
		return (0);
	if (sprite)
		free(sprite);
	return (1);
}

int	importsprite1(t_cub3d *game, char *line)
{
	if (!ft_strncmp(line, "SP3 ", 4))
	{
		if (!spriteload(3, game, line))
			return (printf("File Not Found :%s\n", &line[4]));
	}
	if (!ft_strncmp(line, "SP4 ", 4))
	{
		if (!spriteload(4, game, line))
			return (printf("File Not Found :%s\n", &line[4]));
	}
	return (0);
}

int	importsprite(t_cub3d *game, char *line)
{
	if (!ft_strncmp(line, "\n", 1))
		return (0);
	if (!ft_strncmp(line, "SP0 ", 4))
	{
		if (!spriteload(0, game, line))
			return (printf("File Not Found :%s\n", &line[4]));
	}
	if (!ft_strncmp(line, "SP1 ", 4))
	{
		if (!spriteload(1, game, line))
			return (printf("File Not Found :%s\n", &line[4]));
	}
	if (!ft_strncmp(line, "SP2 ", 4))
	{
		if (!spriteload(2, game, line))
			return (printf("File Not Found :%s\n", &line[4]));
	}
	return (importsprite1(game, line));
}
