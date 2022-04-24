/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:18:39 by aeryilma          #+#    #+#             */
/*   Updated: 2022/04/24 02:48:25 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "signal.h"

unsigned char	g_gelen = 0;

void	birsinyal(int sig)
{
	static int	bit = 0;

	if (bit == 0)
		g_gelen = 0;
	g_gelen <<= 1;
	if (sig == 31)
		g_gelen += 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", g_gelen);
		bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, birsinyal);
	signal(SIGUSR2, birsinyal);
	ft_printf("pid : %d\n", pid);
	while (1)
		;
}
