/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animatedsprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 05:25:07 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/15 06:04:43 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	nextframe(t_cub3d *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->texture.sprite[i] == game->texture.lastanimation)
			break ;
		i++;
	}
	if (i == 4)
	{
		game->texture.lastanimation = game->texture.sprite[0];
		return ;
	}
	while (!(game->texture.sprite[i + 1]))
	{
		i++;
		if (i < 5)
			break ;
	}
	if (i + 1 < 5)
		game->texture.lastanimation = game->texture.sprite[i + 1];
	else
		return ;
}
