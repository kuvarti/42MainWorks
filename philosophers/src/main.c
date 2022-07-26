/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/26 16:34:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_sim	*fillsim(char **argv)
{
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	sim->d_timeout = ft_atoi(argv[2]);
	sim->e_timeout = ft_atoi(argv[3]);
	sim->s_timeout = ft_atoi(argv[4]);
	if (argv[5])
		sim->eat_times = ft_atoi(argv[5]);
	else
		sim->eat_times = 0;
	return (sim);
}

int	main(int argc, char **argv)
{
	t_sim	*sim;

	if (argc != 5 && argc != 6)
		return (0 * printf("Yanlıs sayıda arguman girdiniz\n"));
	sim = fillsim(argv);
	printf("%d", sim->d_timeout);
}
