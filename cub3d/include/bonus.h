/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:20:22 by aeryilma          #+#    #+#             */
/*   Updated: 2023/02/14 05:53:22 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "structures.h"

void	switchdoor(t_cub3d *game);
void	getminimap(t_cub3d *game);
void	setbonuspos(t_cub3d *game, double newposx, double newposy, char mod);

#endif
