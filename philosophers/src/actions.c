/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:42:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/09 13:17:34 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
static int	look_lfork(t_philo *philo, int phil)
{
	if (philo[phil - 1].id)
		return (philo[phil - 1].id);
	else
		return (0);
}

void	eating(t_philo *philo, t_sim *sim, int phil)
{
	//! take forks
	philo[phil].diecd = sim->e_timeout;
	//! break forks
	sleeping(philo, sim, phil);
}

void	sleeping(t_philo *philo, t_sim *sim, int phil)
{
	if (philo[phil].diecd + sim->s_timeout < sim->d_timeout)
	{
		usleep(sim->s_timeout * 1000);
		thinking(philo, sim, phil);
	}
	else
	{
		usleep((philo[phil].diecd - sim->s_timeout) * 1000);
		print_status(philo, sim, phil);
		pthread_detach(philo[phil].thread);
		return ;
	}
}

void	thinking(t_philo *philo, t_sim *sim, int phil)
{
	while (1)
	{
		if (philo[phil].fork == 1 && philo[look_lfork(philo, phil)].fork == 1)
			eating(philo, sim, phil);
		usleep(5 * 1000);
		philo[phil].diecd += 5;
		if (philo[phil].diecd > sim->d_timeout)
		{
			//! died!!
			pthread_detach(philo[phil].thread);
			break ;
		}
	}
}
*/
