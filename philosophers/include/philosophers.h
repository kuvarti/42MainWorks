/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:31:21 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/29 17:24:15 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

// STRUCTURES
typedef struct s_simulation
{
	struct timeval	start_time;
	int				p_count;
	int				d_timeout;
	int				e_timeout;
	int				s_timeout;
	int				eat_times;
}	t_sim;

typedef struct s_philosophers
{
	int			id;
	int			eat;
	char		fork;
	char		state;
	int			diecd;
	pthread_t	thread;
}	t_philo;

typedef struct s_barrel
{
	t_sim	*sim;
	t_philo	*philo;
}	t_barrel;


// STATES
# define DEAD 'd'
# define EATING	'e'
# define SLEEPING 's'
# define THINKING 't'

// ACTIONS
void	eating(t_philo *philo, t_sim *sim, int phil);
void	sleeping(t_philo *philo, t_sim *sim, int phil);
void	thinking(t_philo *philo, t_sim *sim, int phil);

// UTILS
long	total_time(t_sim *sim);
int		ft_atoi(const char *nptr);
void	print_status(t_philo *philo, t_sim *sim, int phil);
void	prepare_sim(char **argv, t_philo **philo, t_sim **sim);

#endif
