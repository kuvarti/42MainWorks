/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:19:57 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/03 00:10:22 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "structures.h"

void		raycast(t_cub3d *game);
double		getperpwalldist(t_raycast *ray);
t_raycast	initraycast(t_cub3d *game);
t_raycast	setwall(t_cub3d *game, t_raycast *ray);
t_raycast	raycastloopstart(t_raycast *ray, int x);

#endif
