/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/01 18:04:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*born_philo(void *sim)
{
	printf("%d. thread olustu\n", ((t_sim *)sim)->philos->id);
	return (sim);
}

void	create_threads(t_sim *sim)
{
	int		i;

	i = 0;
	while (i++ < sim->p_count)
	{
		pthread_create(&(sim->philos->thread), NULL, born_philo, (void *)sim);
		sim->philos = sim->philos->next;
	}
}

void	start_sim(t_sim *sim)
{
	create_threads(sim);
}

int	main(int argc, char **argv)
{
	t_sim		*sim;

	if (argc != 5 && argc != 6)
		return (0 * printf("Yanlıs sayıda arguman girdiniz\n"));
	prepare_sim(argv, &sim);
	start_sim(sim);
	usleep(10 * TO_UP);
}
