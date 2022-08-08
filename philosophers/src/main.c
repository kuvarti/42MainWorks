/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/08 14:35:17 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex;

void	*born_philo(void *sim)
{
	usleep(50 * TO_UP);
	printf("%p(%i). thread olustu %ld.ms\n", &(((t_philo *)sim)->id), ((t_philo *)sim)->id, total_time(((t_philo *)sim)->sim));
	return (sim);
}

void	create_threads(t_sim *sim, t_philo *philo)
{
	int		i;

	gettimeofday(&(sim->start_time), NULL);
	i = -1;
	while (++i < sim->p_count)
	{
		printf("here we gooo %ld\n", total_time(sim));
		pthread_create(&philo[i].thread, NULL, born_philo, &philo[i]);
	}
	i = -1;
	while (++i < sim->p_count)
		pthread_join(philo[i].thread, NULL);
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
		return (0 * printf("Usage: ./philo tt_die tt_eat tt_sleep <eat_count>\n"));
	prepare_sim(argv, &sim, &philo);
	pthread_mutex_init(&mutex, NULL);
	start_sim(sim, philo);
}
