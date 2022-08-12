/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:01:18 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/12 17:36:17 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sim_status(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo[i].id)
	{
		if (philo[i].state == DEAD)
			return (0);
		i++;
	}
	return (i);
}

void	printmessage(t_philo *philo, char state)
{
	if (state == FORK)
		printf("%ld %d has taken a fork\n", total_time(philo->sim), philo->id);
	else if (state == EATING)
		printf("%ld %d is eating\n", total_time(philo->sim), philo->id);
	else if (state == SLEEPING)
		printf("%ld %d is sleeping\n", total_time(philo->sim), philo->id);
	else if (state == THINKING)
		printf("%ld %d is thinking\n", total_time(philo->sim), philo->id);
	else if (state == DEAD)
		printf("%ld %d is dead\n", total_time(philo->sim), philo->id);
}
