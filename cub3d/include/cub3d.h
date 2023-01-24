/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:28:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/24 05:28:39 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*		Custom LIBs
#include "mlx.h"
#include "libft.h"
#include "events.h"
#include "maplib.h"
#include "defines.h"

//*		System LIBs
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	g_vectord
{
	double	X;
	double	Y;
}	t_vectord;

typedef struct	g_chararacter
{
	t_vectord	pos;
	t_vectord	delta;
	double		angle;
}	t_character;

typedef struct	g_cub3d
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data		img;
	t_onkeys	onkey;
	t_character	*player;
}	t_cub3d;

//*	init
int	initialize(t_cub3d *init, char **argv);

//*	mapcontrol
int	mapcheck(char **map);
int	mapgenerate(t_cub3d *game, char *file);

//*	EVENTS
int	getkeys(int	keycode, t_cub3d *game);
int	finish(t_cub3d *cub3d);

#endif
