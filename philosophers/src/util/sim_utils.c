/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:01:18 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/11 18:01:28 by aeryilma         ###   ########.fr       */
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
