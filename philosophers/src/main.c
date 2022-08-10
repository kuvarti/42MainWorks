/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 21:08:39 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*born_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->sim->forks[0]));
	ft_printf("sa %i \n", philo->id);
	pthread_mutex_unlock(&(philo->sim->forks[0]));
	return (arg);
}


void	*deadcheck(void *philos)
{
	int	i;
	int	j;

	while (1)
	{
		i = 0;
		j = 0;
		while (((t_philo *)philos)[i].thread)
		{
			if (((t_philo *)philos)[i].state == DEAD)
			{
				j = -1;
				while (((t_philo *)philos)[++j].id)
				{
					if (((t_philo *)philos)[j].thread)
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
	pthread_create(&(sim->checker), NULL, deadcheck, philo);
	i = -1;
	while (++i < (philo[0].sim->p_count))
		pthread_join(philo[i].thread, NULL);
	pthread_join(sim->checker, NULL);

}

int	main(int argc, char **argv)
{
	t_sim	*sim;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0 * printf("Usage: ./philo tt_die tt_eat tt_sleep <eat_count>\n"));
	if (!prep_sim(&sim, &philo, argv))
		return (0);
	create_threads(sim, philo);
}
