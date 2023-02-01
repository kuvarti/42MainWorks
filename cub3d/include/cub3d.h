/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:28:44 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/01 22:36:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//*		Custom LIBs
# include "mlx.h"
# include "libft.h"
# include "structures.h"
# include "defines.h"
# include "raycast.h"
# include "events.h"

//*		System LIBs
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

//*	init
int		initialize(t_cub3d *init, char **argv);
int		initialize_player(t_cub3d *game);
int		initialize_image(t_cub3d *game);
int		importxpm(t_cub3d *game, char *line);

//*	Draw
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
size_t	get_texture_color(t_data *texture, int pixel_x, int pixel_y);

void	getscreen(t_cub3d *game);

//*	mapcontrol
int		mapcheck(char **map);
int		mapgenerate(t_cub3d *game, char *file);

//* Utils
int		abs(int n);
double	dabs(double n);

#endif
