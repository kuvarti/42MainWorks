/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:07:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/29 12:08:30 by aeryilma         ###   ########.fr       */
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

static t_philo	*createphilo(int pcount, const t_sim *sim)
{
	t_philo *philo;
	int	i;

	philo = malloc(sizeof(philo) * (pcount + 1));
	i = 1;
	while (i <= pcount)
	{
		philo[i - 1].id = i;
		philo[i - 1].fork = 1;
		philo[i - 1].state = THINKING;
		if (sim->eat_times)
			philo[i - 1].eat = sim->eat_times;
		else
			philo[i - 1].eat = -1;
		i++;
	}
	philo[i].id = 0;
	philo[i].fork = 0;
	philo[i].state = 0;
	philo[i].eat = -1;
	return (philo);
}

void	prepare_sim(char **argv, t_philo **philo, t_sim **sim)
{
	*sim = fillsim(argv);
	*philo = createphilo(ft_atoi(argv[1]), *sim);
//	((*sim)->start_time) = malloc(sizeof(struct timeval));
	gettimeofday(&((*sim)->start_time), NULL);
}
