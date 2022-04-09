/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:50:40 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/07 08:25:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# ifndef SOLONG_H
#  include "solong.h"
# endif

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_sprites
{
	int		sprlen;
	char	*duvar;
	char	*zemin;
	char	*karakter;
	char	*havlu;
	char	*gemi;
}	t_sprites;

int		girdial(int keycode, t_game *oyun);
void	git(t_game *oyun, int x, int y);
void	mapciz(const t_game *oyun);

#endif
