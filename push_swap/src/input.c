/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:59:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/11 00:40:37 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inputkontrol(char *input, int *arg)
{
	int	i;

	if (input[0] == '0' && !input[1])
	{
		*arg = 0;
		return (1);
	}
	if (input[0] == '-' && input[1] == '1' && !input[2])
	{
		*arg = -1;
		return (1);
	}
	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (0);
		i++;
	}
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	return (*arg);
}
