/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:31:21 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/26 16:32:24 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct s_simulation
{
	int	d_timeout;
	int	e_timeout;
	int	s_timeout;
	int	eat_times;
}	t_sim;

typedef struct s_philosophers
{
	int	id;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif
