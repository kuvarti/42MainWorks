/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/12 19:17:43 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	lookforks(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->sim->forks[philo->id].__sig)
		i++;
	if (philo->sim->forks[philo->id].__sig)
		i++;
	return (2);
}

void	eating(t_philo *philo)
{
	if (!sim_status(philo->sim->philos))
		return ;
	philo->diecd = 0;
	philo->diecd += philo->sim->e_timeout;
	printmessage(philo, EATING);
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

	eating(philo);
	return ;
}
