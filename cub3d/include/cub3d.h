/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:28:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/16 01:40:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*		Custom LIBs
#include "mlx.h"
#include "events.h"

//*		System LIBs
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

typedef struct	g_chararacter
{
	double	posX;
	double	posY;
}	t_character;

typedef struct	g_cub3d
{
	void		*mlx;
	void		*win;
	t_character	*player;
}	t_cub3d;

int	initialize(t_cub3d *init);

#endif
