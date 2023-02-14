/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:20:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 06:33:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "structures.h"

int		mousemove(int x, int y, t_cub3d *game);
void	switchdoor(t_cub3d *game);
void	getminimap(t_cub3d *game);
void	initminimapimage(t_cub3d *game);
void	setbonuspos(t_cub3d *game, double newposx, double newposy, char mod);
void	cursorturn(t_cub3d *game, int key);

#endif
