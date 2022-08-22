/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:58:27 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/21 14:11:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	total_time(t_sim *sim)
{
	long long		sec;
	long long		ms;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	sec = (current_time.tv_sec - sim->start_time.tv_sec) * 1000;
	ms = (current_time.tv_usec - sim->start_time.tv_usec) / 1000;
	return (sec + ms);
}

// return 0 if philo is dead
long	diecheck(t_philo *philo)
{
	if ((total_time(philo->sim) - philo->lastmeat) > philo->sim->d_timeout)
		return (0);
	else
		return (1);
}
