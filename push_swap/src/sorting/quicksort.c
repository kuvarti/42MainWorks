/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:33:07 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/01 16:06:53 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO Not working yet
void	quicksort(t_stack **a, t_stack **b, int min, int max)
{
	int	i;
	int	pivot;
	int	array;

	array = max - min;
	if (array < 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return ;
	}
	while (min--)
		ra(a);
	min = max - array;
	array = max;
	i = 0;
	pivot = (max - min) - (max / 2);
	while (haspush(*a, &pivot))
	{
		while ((*a)->index != pivot)
		{
			if((*a)->index <= pivot)
			{
				pb(a, b);
				continue ;
			}
			if ((*a)->index > (*a)->next->index)
			{
				sa(a);
				continue ;
			}
			ra(a);
			i++;
		}
		pb(a, b);
		pivot--;
	}
	while (i--)
		rra(a);
	while ((*b))
	{
		pa(a, b);
		array--;
	}
	quicksort(a, b, min, (max / 2) - 1);
	quicksort(a, b, max/ 2, max);
}
