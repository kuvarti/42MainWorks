/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:29:10 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/24 02:47:52 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "signal.h"

int	main(int argc, char **argv)
{
	int		index;
	int		pid;
	int		a;

	if (argc != 3)
		return (ft_printf("Dogru format './client pid message' seklindedir\n"));
	pid = ft_atoi(argv[1]);
	index = -1;
	while (argv[2][++index])
	{
		a = 8;
		while (a--)
		{
			usleep(150);
			if (argv[2][index] >> a & 1)
				kill(pid, 31);
			else
				kill(pid, 30);
		}
	}
}
