/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:18:13 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/12 01:15:04 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "fl_mngmnt.h"

int	main(int ac, char **file)
{
	t_game	*oyun;

	if (ac != 2)
		return (ft_printf("%s", "ERROR: Kullanım: ./solong map_file\n") * 0);
	oyun = (t_game *)malloc(sizeof(t_game));
	if (!oyun)
		return (0);
	getmap(oyun, file[1]);
	if (!(oyun -> map))
		return (ft_printf("Error\nMap Bu şekilde olamaz!!\n"));
	else
		baslat(oyun);
	free(oyun);
}
