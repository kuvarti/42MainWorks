/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:14:29 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/12 01:12:45 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fl_mngmnt.h"
#include "ft_printf.h"

static void	kapat(int *fd, char *a, char *b)
{
	close(*fd);
	free(a);
	free(b);
}

static void	freemap(t_game *oyun)
{
	int	i;

	i = 0;
	while (oyun->map[i])
		free(oyun->map[i++]);
	oyun->map = NULL;
	free(oyun);
}

void	getmap(t_game *oyun, char *file)
{
	char	*deneme;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (!fd)
		return ;
	str = 0;
	while (1)
	{
		deneme = get_next_line(fd);
		if (!deneme)
			break ;
		str = ft_gnl_strjoin(str, deneme);
	}
	oyun->map = ft_split(str, '\n');
	kapat(&fd, str, deneme);
	fd = mapcontrol(oyun);
	if (fd == 0)
		freemap(oyun);
}
