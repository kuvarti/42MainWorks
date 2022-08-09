/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:07:16 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/09 11:26:29 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int checknumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0 * printf("Arguments Are not numeric\n"));
		i++;
	}
	i = ft_atoi(str);
	if (i < 60)
		return (0 * printf("Paramaters cannot be lower than 60\n"));
	else if (i == 0 || i == -1)
		return (0 * printf("Parameters must integer"));
	return (1);
}

static int checkargs(char **argv)
{
	int	i;

	i = 1;
	while (argv[++i])
	{
		if (!checknumber(argv[i]))
			return (0);
	}
	if (ft_atoi(argv[1]) < 200)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
				return (0 * printf("Arguments Are not numeric\n"));
			i++;
		}
	}
	else
		return (0 * printf("Maximum philosopher count is 199"));
	return (1);
}

t_sim	*fillsim(char **argv)
{
	int				i;
	t_sim			*sim;
	pthread_mutex_t	*mutexes;

	if (!checkargs(argv))
		return (0);
	sim = malloc(sizeof(t_sim));
	sim->p_count = ft_atoi(argv[1]);
	sim->d_timeout = ft_atoi(argv[2]);
	sim->e_timeout = ft_atoi(argv[3]);
	sim->s_timeout = ft_atoi(argv[4]);
	i = -1;
	mutexes = malloc(sizeof(pthread_mutex_t) * (sim->p_count + 1));
	while (++i < (sim->p_count))
	{
		printf("%i. fork initializing!\n", i);
		pthread_mutex_init(&mutexes[i], NULL);
	}
	//mutexes[i] = (pthread_mutex_t)0;
	sim->forks = mutexes;
	if (argv[5])
		sim->eat_times = ft_atoi(argv[5]);
	else
		sim->eat_times = -1;
	return (sim);
}

t_philo	*createphilo(int pcount, t_sim *sim)
{
	t_philo	*philo;
	int	i;

	philo = malloc(sizeof(t_philo) * (pcount + 1));
	i = 0;
	while (i < pcount)
	{
		philo[i].id = i + 1;
		philo[i].state = THINKING;
		philo[i].sim = sim;
		if (sim->eat_times)
			philo[i].eat = sim->eat_times;
		else
			philo[i].eat = -1;
		i++;
	}
	philo[i].id = 0;
	philo[i].state = 0;
	philo[i].eat = -1;
	return (philo);
}

int	prep_sim(t_sim **sim, t_philo **philo, char **argv)
{
	*sim = fillsim(argv);
	if (!(*sim))
		return (0);
	*philo = createphilo((*sim)->p_count, *sim);
	return (1);
}
