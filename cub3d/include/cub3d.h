/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:28:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/25 21:18:27 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*		Custom LIBs
#include "mlx.h"
#include "libft.h"
#include "structures.h"
#include "defines.h"
#include "events.h"

//*		System LIBs
#include <stdio.h>
#include <fcntl.h>
#include <math.h>

//*	init
int	initialize(t_cub3d *init, char **argv);
int	initialize_player(t_cub3d *game);
int	initialize_image(t_cub3d *game);

void	ciz(t_cub3d *game);

//*	mapcontrol
int	mapcheck(char **map);
int	mapgenerate(t_cub3d *game, char *file);

#endif
