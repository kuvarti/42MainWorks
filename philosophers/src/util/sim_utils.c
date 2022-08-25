/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:01:18 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/26 01:33:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_wait(t_philo *philo, int s_value)
{
	long	max_sleep;

	max_sleep = total_time(philo->sim) + s_value;
	while (max_sleep >= total_time(philo->sim))
	{
		usleep (1000);
		if (!diecheck(philo))
		{
			die(philo);
			return ;
		}
	}
}

void	die(t_philo *philo)
{
	int	i;

	philo->state = DEAD;
	printmessage(philo, DEAD);
	i = 0;
	while (i < philo->sim->p_count)
		pthread_mutex_unlock(&(philo->sim->forks[i++]));
	i = 0;
}

int	sim_status(t_philo *philo, int id)
{
	int	i;

	pthread_mutex_lock(&(philo->sim->checklock));
	i = 0;
	while (philo[i].id)
	{
		if (philo[i++].state == DEAD)
			return (0);
	}
	if (philo->sim->eat_times > 0)
	{
		i = 0;
		while (philo[i].id)
		{
			if (i == id && !(philo[i].eat >= 0))
				return (0);
			if (philo[i].eat >= 0)
				return (1);
			i++;
		}
		if (i == philo->sim->p_count)
			return (0);
	}
	pthread_mutex_unlock(&(philo->sim->checklock));
	return (i);
}

void	printmessage(t_philo *philo, char state)
{
	pthread_mutex_lock(&(philo->sim->printlock));
	if (state == DEAD)
		printf("%ld %d is dead\n", total_time(philo->sim), philo->id);
	if (sim_status(philo->sim->philos, philo->id))
	{
		if (state == FORK)
			printf("%ld %d has taken a fork\n", total_time(philo->sim),
				philo->id);
		else if (state == EATING)
			printf("%ld %d is eating\n", total_time(philo->sim), philo->id);
		else if (state == SLEEPING)
			printf("%ld %d is sleeping\n", total_time(philo->sim), philo->id);
		else if (state == THINKING)
			printf("%ld %d is thinking\n", total_time(philo->sim), philo->id);
		else if (state == DEAD)
			printf("%ld %d is dead\n", total_time(philo->sim), philo->id);
	}
	pthread_mutex_unlock(&(philo->sim->printlock));
}
