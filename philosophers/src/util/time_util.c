/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:58:27 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/29 17:27:30 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	total_time(t_sim *sim)
{
	time_t	sec;
	time_t	ms;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	sec = (current_time.tv_sec - sim->start_time.tv_sec) * 1000;
	ms = current_time.tv_usec - sim->start_time.tv_usec;
	return (sec + ms);
}

void	print_status(t_philo *philo, t_sim *sim, int phil)
{
	long	ttime;

	ttime = total_time(sim);
	if (philo[phil].state == EATING)
	{
		printf("%ld %d has taken a fork", ttime, phil);
		printf("%ld %d is eating", ttime, phil);
	}
	else if (philo[phil].state == SLEEPING)
		printf("%ld %d is sleeping", ttime, phil);
	else if (philo[phil].state == THINKING)
		printf("%ld %d is thinking", ttime, phil);
	else if (philo[phil].state == DEAD)
		printf("%ld %d is dead", ttime, phil);
}
