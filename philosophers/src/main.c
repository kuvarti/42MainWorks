/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/03 17:33:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex;

void	*born_philo(void *sim)
{
	pthread_mutex_lock(&mutex);
	usleep(100 * TO_UP);
	printf("%p(%i). thread olustu\n", &(((t_sim *)sim)->philo->id), ((t_sim *)sim)->philo->id);
	pthread_mutex_unlock(&mutex);
	return (sim);
}

void	create_threads(t_sim *sim, t_philo *philo)
{
	int		i;

	i = 0;
	while (i++ < sim->p_count)
	{
		pthread_mutex_lock(&mutex);
		sim->philo = &philo[i - 1];
		printf("sending %p(%i)\n", &(sim->philo->id), sim->philo->id);
		pthread_create(&philo[i - 1].thread, NULL, born_philo, (void *)sim);
		pthread_mutex_unlock(&mutex);
	}
	i = 0;
	while (i++ < sim->p_count)
	{
		pthread_join(sim->philo->thread, NULL);
	}
}

void	start_sim(t_sim *sim, t_philo *philos)
{
	create_threads(sim, philos);
}

int	main(int argc, char **argv)
{
	t_sim	*sim;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (0 * printf("Yanlıs sayıda arguman girdiniz\n"));
	prepare_sim(argv, &sim, &philo);
	pthread_mutex_init(&mutex, NULL);
	printf("a");
int i;
i = 0;
while ((*sim).forks->fork_status)
{
	sim->forks[i++].fork_status = 1;
}
	start_sim(sim, philo);
}
