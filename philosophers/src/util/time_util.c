/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:58:27 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/11 10:34:55 by aeryilma         ###   ########.fr       */
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
