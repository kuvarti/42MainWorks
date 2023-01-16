/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgenerate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:49:04 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/16 20:51:10 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapgenerate(t_cub3d *game, char *file)
{
	game->player = malloc(sizeof(t_character));
	if (ft_strlen(file) < 5 || ft_strrcmp(file, ".cub") != 0)
		return (printf("Wrong file format: correct file format: file.cub\n"));
	return (0);
}
