/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/26 01:53:25 by aeryilma         ###   ########.fr       */
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

void	takeforks(t_philo *philo)
{
	pthread_mutex_lock(&(philo->sim->forks[philo->id - 1]));
	printmessage(philo, FORK);
	if (!diecheck(philo))
	{
		die(philo);
		return ;
	}
	pthread_mutex_lock(&(philo->sim->forks[leftfork(philo)]));
	printmessage(philo, FORK);
	if (!diecheck(philo))
	{
		die(philo);
		return ;
	}
}

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
	philo_wait(philo, philo->sim->e_timeout);
	pthread_mutex_unlock(&(philo->sim->forks[philo->id - 1]));
	pthread_mutex_unlock(&(philo->sim->forks[leftfork(philo)]));
	sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	if (!sim_status(philo->sim->philos, philo->id))
		return ;
	printmessage(philo, SLEEPING);
	philo_wait(philo, philo->sim->s_timeout);
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	if (!sim_status(philo->sim->philos, philo->id))
		return ;
	printmessage(philo, THINKING);
	takeforks(philo);
	eating(philo);
	return ;
}
