/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:03:06 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/14 23:38:32 by aeryilma         ###   ########.fr       */
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

typedef struct s_sprites
{
	int		sprlen;
	void	*duvar;
	void	*zemin;
	void	*karakter;
	void	*rkarakter;
	void	*dusman;
	void	*gemi;
	void	*havlu;
	void	*havlu1;
	void	*havlu2;
	void	*havlu3;
}	t_sprites;

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
	t_sprites		sprite;
	unsigned char	animtime;
}	t_game;

void	baslat(t_game *oyun);
void	spritedoldur(t_game *oyun);
int	bitir(t_game *oyun, char *msg);

#endif
