/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:59:02 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/30 20:59:40 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "cub3d.h"

int		keydown(int keycode, t_cub3d *game);
int		keyup(int keycode, t_cub3d *game);
int		basic_loop(t_cub3d *game);
int		init_event(t_cub3d *game);

//*	Utils
float	getmvspeed(void);
int		retmove(t_cub3d *game);
int		move(t_cub3d *game);
int		finish(t_cub3d *game);

#endif
