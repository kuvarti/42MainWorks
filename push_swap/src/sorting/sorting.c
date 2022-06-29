/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/29 14:17:38 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ? ITS A WORSTEST SORTING

void	pushpart(t_stack **a, t_stack **b, int max, int len)
{
	while (len)
	{
		if ((*a)->index <= max)
		{
			pb(a, b);
			continue ;
		}
		ra(a);
		len--;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	index;
	int	i;

	i = stacklen(*a);
	index = i / 5;
	while (index < i)
	{
		pushpart(a, b, index, i);
		break;
	}
}
