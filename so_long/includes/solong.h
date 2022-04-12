/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:03:06 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/12 03:13:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# ifndef FT_PRINTF_H
#  include "ft_printf.h"
# endif

# ifndef MLX_H
#  include "mlx.h"
# endif

typedef struct s_konum
{
	int	x;
	int	y;
}	t_konum;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

# define SOL -1
# define SAG 1
# define YUKARI 2
# define ASAGI -2

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	int				haraket_sayisi;
	int				coincount;
	char			**map;
	t_konum			pos;
	char			yon;
	char			durum;
	unsigned char	animtime;
}	t_game;

void	baslat(t_game *oyun);

#endif
