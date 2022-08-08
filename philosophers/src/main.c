/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/08 22:50:11 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*born_philo(void *sim)
{
	usleep(((200 * ((t_philo *)sim)->id) + ((t_philo *)sim)->id) * TO_UP);
	printf("%p(%i). thread olustu %ld.ms\n", &(((t_philo *)sim)->id), ((t_philo *)sim)->id, total_time(((t_philo *)sim)->sim));
	return (sim);
}

void	create_threads(t_sim *sim, t_philo *philo)
{
	int		i;

	i = -1;
	gettimeofday(&(sim->start_time), NULL);
	while (++i < sim->p_count)
	{
		pthread_create(&philo[i].thread, NULL, born_philo, &philo[i]);
	}
	i = -1;
	while (++i < sim->p_count)
		pthread_join(philo[i].thread, NULL);
}

void	*deadcheck(void *philos)
{
	int	i;
	int	j;

	i = 0;
	while (((t_philo *)philos)[i].id)
	{
		if (((t_philo *)philos)[i].state == THINKING)
		{
			j = 0;
			while (((t_philo *)philos)[j].id)
				pthread_detach(((t_philo *)philos)[j++].thread);
		}
		i++;
	}
	return ((void *)0);
}

void	start_sim(t_sim *sim, t_philo **philos)
{
	create_threads(sim,  *philos);
	//pthread_create(&(sim->checker), NULL, deadcheck, *philos);
	//pthread_join(sim->checker, NULL);
}

int	main(int argc, char **argv)
{
	t_sim	*sim;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0 * printf("Usage: ./philo tt_die tt_eat tt_sleep <eat_count>\n"));
	if (!prep_sim(&sim, &philo, argv))
		return (0);
	start_sim(sim, &philo);
}
