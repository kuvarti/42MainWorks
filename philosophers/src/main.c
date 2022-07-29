/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:05:50 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/29 17:29:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*say(void *barrel)
{
	usleep(10000);
	printf("%ld", total_time(((t_barrel *)barrel)->sim));
	return (barrel);
}

void	start_sim(t_philo *philos, t_sim *sim)
{
	t_barrel	*barrel;
	int			i;

	barrel = malloc(sizeof(t_barrel));
	barrel->sim = sim;
	barrel->philo = philos;
	i = 1;
	while (philos[i - 1].id)
	{
		pthread_create(&philos[i - 1].thread, NULL, say, (void *)barrel);
		i++;
	}
	sim++;
}

int	main(int argc, char **argv)
{
	t_sim	*sim;
	t_philo	*philos;
	t_barrel	*barrel;

	if (argc != 5 && argc != 6)
		return (0 * printf("Yanlıs sayıda arguman girdiniz\n"));
	prepare_sim(argv, &philos, &sim);
	barrel = malloc(sizeof(t_barrel));
	barrel->sim = sim;
	barrel->philo = philos;
	start_sim(philos, sim);
	pthread_join(philos[0].thread, (void *)barrel);
}
