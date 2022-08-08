/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:07:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/08 14:35:24 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_sim	*fillsim(char **argv)
{
	int		i;
	t_sim	*sim;

	sim = malloc(sizeof(t_sim));
	sim->p_count = ft_atoi(argv[1]);
	sim->d_timeout = ft_atoi(argv[2]);
	sim->e_timeout = ft_atoi(argv[3]);
	sim->s_timeout = ft_atoi(argv[4]);
	if (argv[5])
		sim->eat_times = ft_atoi(argv[5]);
	else
		sim->eat_times = 0;
	sim->forks = malloc(sizeof(t_forks) * (sim->p_count + 1));
	i = 0;
	while (i < sim->p_count)
	{
		sim->forks[i++].fork_status = 1;
	}

	return (sim);
}

static t_philo	*createphilo(int pcount, t_sim *sim)
{
	t_philo *philo;
	int	i;

	philo = malloc(sizeof(t_philo) * (pcount + 1));
	i = 0;
	while (i < pcount)
	{
		philo[i].id = i + 1;
		philo[i].fork = 1;
		philo[i].state = THINKING;
		philo[i].sim = sim;
		if (sim->eat_times)
			philo[i].eat = sim->eat_times;
		else
			philo[i].eat = -1;
		i++;
	}
	philo[i].id = 0;
	philo[i].fork = 0;
	philo[i].state = 0;
	philo[i].eat = -1;
	return (philo);
}

void	prepare_sim(char **argv, t_sim **sim, t_philo **philo)
{
	*sim = fillsim(argv);
	*philo = createphilo((*sim)->p_count, *sim);
}
