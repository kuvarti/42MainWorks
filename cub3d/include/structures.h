/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:12:56 by aeryilma          #+#    #+#             */
/*   Updated: 2023/01/25 21:15:42 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include <stdlib.h>

typedef struct s_onkeys
{
	int	keyw;
	int	keya;
	int	keys;
	int	keyd;
	int	keyup;
	int	keydown;
	int	keyleft;
	int	keyright;
}	t_onkeys;

typedef struct s_map
{
	char	**map;
	size_t	x;
	size_t	y;
}	t_map;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_vectord
{
	double	X;
	double	Y;
}	t_vectord;

typedef struct	s_chararacter
{
	t_vectord	pos;
	t_vectord	delta;
	double		angle;
}	t_character;

typedef struct	s_cub3d
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data		*img;
	t_onkeys	onkey;
	t_character	*player;
}	t_cub3d;

#endif
