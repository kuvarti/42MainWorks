/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/19 13:16:30 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		leftfork(t_philo *philo)
{
	if (philo->id > 1)
		return (philo->id - 2);
	else
		return (philo->sim->p_count - 1);
}

int	lookforks(t_philo *philo)
{
	int	i;

	if (philo->sim->p_count < 2)
		return (1);
	pthread_mutex_lock(&(philo->sim->checklock));
	i = 0;
	if (philo->sim->forks[philo->id - 1].__sig)
		i++;
	if (philo->sim->forks[leftfork(philo)].__sig)
		i++;
	pthread_mutex_unlock(&(philo->sim->checklock));
	return (i);
}

void	eating(t_philo *philo)
{
	if (!sim_status(philo->sim->philos))
		return ;
	philo->eat--;
	philo->diecd = 0;
	philo->diecd += philo->sim->e_timeout;
	printmessage(philo, EATING);
	usleep(philo->sim->e_timeout * TO_UP);
	pthread_mutex_unlock(&(philo->sim->forks[philo->id - 1]));
	pthread_mutex_unlock(&(philo->sim->forks[leftfork(philo)]));
	sleeping(philo);
}

void	sleeping(t_philo *philo)
{
	if (!sim_status(philo->sim->philos))
		return ;
	printmessage(philo, SLEEPING);
	philo->diecd += philo->sim->s_timeout;
	if (philo->diecd > philo->sim->d_timeout)
	{
		usleep((philo->diecd - philo->sim->d_timeout) * TO_UP);
		philo->state = DEAD;
		printmessage(philo, DEAD);
		return ;
	}
	usleep((philo->sim->s_timeout) * TO_UP);
	thinking(philo);
}

void	thinking(t_philo *philo)
{
	if (!sim_status(philo->sim->philos))
		return ;
	printmessage(philo, THINKING);
	while (lookforks(philo) != 2)
	{
		if (philo->diecd > philo->sim->d_timeout)
		{
			philo->state = DEAD;
			printmessage(philo, DEAD);
			return ;
		}
		usleep(5 * TO_UP);
		philo->diecd += 5;
	}
	pthread_mutex_lock(&(philo->sim->forks[philo->id - 1]));
	printmessage(philo, FORK);
	pthread_mutex_lock(&(philo->sim->forks[leftfork(philo)]));
	printmessage(philo, FORK);
	eating(philo);
	return ;
}
