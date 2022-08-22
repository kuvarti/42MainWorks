/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/22 13:56:32 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	leftfork(t_philo *philo)
{
	if (philo->id > 1)
		return (philo->id - 2);
	else
		return (philo->sim->p_count - 1);
}

/*
void	*waiting(void *arg)
{
	char	st;
	t_philo	*philo;

	philo = (t_philo *)arg;
	st = philo->state;
	while (diecheck(philo))
		usleep(1 * TO_UP);
	if (!diecheck(philo))
		die(philo);
	return (philo);
}
*/

void	eating(t_philo *philo)
{
	if (!sim_status(philo->sim->philos, philo->id))
		return ;
	if (!diecheck(philo))
	{
		die(philo);
		return ;
	}
	philo->eat--;
	philo->lastmeat = total_time(philo->sim);
	printmessage(philo, EATING);
	usleep(philo->sim->e_timeout * TO_UP);
	pthread_mutex_unlock(&(philo->sim->forks[philo->id - 1]));
	pthread_mutex_unlock(&(philo->sim->forks[leftfork(philo)]));
	sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	if (!sim_status(philo->sim->philos, philo->id))
		return ;
	printmessage(philo, SLEEPING);
	if ((philo->lastmeat + philo->sim->s_timeout)
		> (philo->lastmeat + philo->sim->d_timeout))
	{
		usleep((philo->lastmeat + philo->sim->d_timeout)
			- (philo->lastmeat + philo->sim->s_timeout));
		die(philo);
		return ;
	}
	usleep((philo->sim->s_timeout) * TO_UP);
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	if (!sim_status(philo->sim->philos, philo->id))
		return ;
	printmessage(philo, THINKING);
	//pthread_create(&(philo->wait), NULL, waiting, (void *)philo);
	pthread_mutex_lock(&(philo->sim->forks[philo->id - 1]));
	printmessage(philo, FORK);
	pthread_mutex_lock(&(philo->sim->forks[leftfork(philo)]));
	printmessage(philo, FORK);
	eating(philo);
	return ;
}
