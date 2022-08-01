/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:07:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/01 17:34:09 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_sim	*fillsim(char **argv)
{
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
	return (sim);
}

/*
static t_philo	*createphilo(int pcount, const t_sim *sim)
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
*/

static t_philo	*createphilo(int pcount, const t_sim *sim)
{
	t_philo	*ret;

	ret = malloc(sizeof(t_philo));
	ret->id = pcount;
	ret->fork = 1;
	ret->state = THINKING;
	if (sim->eat_times)
		ret->eat = sim->eat_times;
	else
		ret->eat = -1;
	ret->next = NULL;
	return (ret);
}

static t_philo	*createphilosophers(const t_sim *sim)
{
	t_philo	*ret;
	t_philo	*tmp;
	t_philo	*last;
	int		i;

	i = 1;
	ret = createphilo(1, sim);
	last = ret;
	while (i < sim->p_count)
	{
		tmp = createphilo(i + 1, sim);
		last->next = tmp;
		tmp->next = ret;
		last = tmp;
		i++;
	}
	return (ret);
}

void	prepare_sim(char **argv, t_sim **sim)
{
	*sim = fillsim(argv);
	(*sim)->philos = createphilosophers(*sim);
//	((*sim)->start_time) = malloc(sizeof(struct timeval));
	gettimeofday(&((*sim)->start_time), NULL);
}
