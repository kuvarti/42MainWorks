/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:18:39 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/10 14:40:23 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "signal.h"

void	handler(int sig)
{
	ft_printf("ben öldüm %d\n", sig);
	kill(getpid());
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGINT, handler);
	while (1)
	{
		ft_printf("pid . : %d\n", pid);
		sleep (1);
	}
}
