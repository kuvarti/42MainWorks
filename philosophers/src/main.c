/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/25 19:55:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lifecycle(t_philo *philo)
{
	if (philo->sim->p_count % 2 == 0)
	{
		if ((philo->id - 1) % 2 == 0)
			sleeping(philo);
		else if ((philo->id - 1) % 2 == 1)
		{
			takeforks(philo);
			eating(philo);
		}
	}
	else
	{
		if ((philo->id - 1) % 3 == 0)
			sleeping(philo);
		else if ((philo->id - 1) % 3 == 1)
		{
			takeforks(philo);
			eating(philo);
		}
		else
			thinking(philo);
	}
}

void	*born_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->sim->p_count <= 1)
	{
		pthread_mutex_lock(&(philo->sim->forks[philo->id - 1]));
		printmessage(philo, FORK);
		usleep(philo->sim->d_timeout * TO_UP);
		die(philo);
		return ((void *)0);
	}
	lifecycle(philo);
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
	while (++i < (philo[0].sim->p_count))
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (i++ < (philo[0].sim->p_count))
		pthread_detach(philo[i].thread);
}

int	main(int argc, char **argv)
{
	t_sim	*sim;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0 * printf("Usage: ./philo t_die t_eat t_sleep <eat_count>\n"));
	if (!prep_sim(&sim, &philo, argv))
		return (0);
	create_threads(sim, philo);
	return (0);
}
