/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/09 17:54:16 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*born_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("%p(%i). thread olustu %ld.ms\n", &(philo->id), philo->id, total_time(philo->sim));

	while (1)
	{
		if (total_time(philo->sim) > 2 * TO_UP)
			philo->state = DEAD;
		usleep((1000 + (0 * printf("%d is still working time is:%ld\n", philo->id, total_time(philo->sim)))) * TO_UP);
	}
	//printf("%p(%d). fork initialized!\n", &(philo->sim->forks[(philo->id) - 1].__sig), (philo->id) - 1);
	//pthread_mutex_lock(&(philo->sim->forks[(philo->id) - 1]));
	return (arg);
}


void	*deadcheck(void *philos)
{
	int	i;
	int	j;

	while (1)
	{
		i = 0;
		while (((t_philo *)philos)[i].thread)
		{
			if (((t_philo *)philos)[i].state == DEAD)
			{
				j = -1;
				while (((t_philo *)philos)[++j].id)
				{
					pthread_detach(((t_philo *)philos)[j].thread);
				}
				break ;
			}
			i++;
		}
		if (j == ((t_philo *)philos)[0].sim->p_count)
			break ;

		usleep(5 * TO_UP);
	}
	return ((void *)0);
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
	pthread_create(&(sim->checker), NULL, deadcheck, philo);
	pthread_join(sim->checker, NULL);
	while (++i < sim->p_count)
		pthread_join(philo[i].thread, NULL);
}

void	start_sim(t_sim *sim, t_philo **philos)
{
	create_threads(sim,  *philos);
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



	usleep(100 * TO_UP);

}
