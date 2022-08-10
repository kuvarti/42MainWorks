/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:31:21 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/10 18:09:47 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"
# include "ft_printf.h"

// STRUCTURES
typedef struct s_simulation
{
	struct timeval			start_time;
	pthread_mutex_t			*forks;
	int						p_count;
	int						d_timeout;
	int						e_timeout;
	int						s_timeout;
	int						eat_times;
	pthread_t				checker;
}	t_sim;

typedef struct s_philosophers
{
	int						id;
	int						eat;
	char					state;
	int						diecd;
	struct s_simulation		*sim;
	pthread_t				thread;
}	t_philo;

# define TO_UP 1000

// STATES
# define DEAD 'd'
# define EATING 'e'
# define SLEEPING 's'
# define THINKING 't'

// ACTIONS
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

// UTILS
long	total_time(t_sim *sim);
int		ft_atoi(const char *nptr);
int		sim_status(t_philo *philo);
void	print_status(t_philo *philo, t_sim *sim, int phil);

// STARTS SIMULATIONS
int		prep_sim(t_sim **sim, t_philo **philo, char **argv);

#endif
