/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:31:21 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/26 01:53:49 by aeryilma         ###   ########.fr       */
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
	struct timeval			start_time;
	struct s_philosophers	*philos;
	pthread_mutex_t			*forks;
	pthread_mutex_t			printlock;
	pthread_mutex_t			checklock;
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
	long					lastmeat;
	struct s_simulation		*sim;
	pthread_t				thread;
	pthread_t				wait;
}	t_philo;

# define TO_UP 1000

// STATES
# define DEAD 'd'
# define EATING 'e'
# define SLEEPING 's'
# define THINKING 't'
# define FORK 'f'

// ACTIONS
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
int		leftfork(t_philo *philo);

// UTILS
void	philo_wait(t_philo *philo, int s_value);
void	takeforks(t_philo *philo);

void	*waiting(void *arg);
void	die(t_philo *philo);
long	total_time(t_sim *sim);
long	diecheck(t_philo *philo);
int		leftfork(t_philo *philo);
int		ft_atoi(const char *nptr);
int		sim_status(t_philo *philo, int id);
void	printmessage(t_philo *philo, char state);

// STARTS SIMULATIONS
int		prep_sim(t_sim **sim, t_philo **philo, char **argv);

#endif
