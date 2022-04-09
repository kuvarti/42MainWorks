/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_mngmnt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:14:26 by aeryilma          #+#    #+#             */
/*   Updated: 2022/03/29 23:44:18 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_MNGMNT_H
# define FL_MNGMNT_H

# ifndef SOLONG_H
#  include "solong.h"
# endif

typedef struct s_mapcheck
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;
}	t_mapcheck;

void	getmap(t_game *oyun, char *file);
char	mapcontrol(t_game *oyun);

#endif
