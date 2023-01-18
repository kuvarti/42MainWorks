/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:28:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/19 00:52:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*		Custom LIBs
#include "mlx.h"
#include "libft.h"
#include "events.h"
#include "maplib.h"

//*		System LIBs
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

# define SCREEN_WIDTH 300
# define SCREEN_HEIGH 300

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	g_chararacter
{
	double	posX;
	double	posY;
}	t_character;

typedef struct	g_cub3d
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data		img;
	t_character	*player;
}	t_cub3d;

int	mapcheck(char **map);
int	mapgenerate(t_cub3d *game, char *file);
int	initialize(t_cub3d *init, char **argv);

#endif
