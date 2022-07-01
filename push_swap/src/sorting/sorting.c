/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/01 17:18:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! ITS NOT WORKING NOW

void	stage_sorter(t_stack **a, t_stack **b, int min, int max)
{
	int	i;

	min = 0;
	while (kontrol(*b, max, 0))
	{
		i = kontrol(*b, max, 0);
		while (i--)
		{
			rb(b);
		}
		pa(a, b);
		max--;
		if (min == max)
			break ;
	}





	// ? Onemsiz
	min = !max;
	a = b;
}

static void	stage_pusher(t_stack **a, t_stack **b, int max)
{
	while (haspush(*a, &max))
	{
		while ((*a)->index != max)
		{
			if((*a)->index <= max)
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
		}
		pb(a, b);
		max--;
	}
}

static void	stage_handler(t_stack **a, t_stack **b, int min, int max)
{
	int	len;

	len = stacklen(*a);
	stage_pusher(a, b, max);
	stage_sorter(a, b, min, max);
}

void	sort(t_stack **a, t_stack **b)
{
	int	stage;
	int	index;
	int	max;

	max = stacklen(*a);
	stage = 1;
	while (stage < 6)
	{
		index = (max / 5) * stage;
		stage_handler(a, b, (max / 5) * (stage - 1), index - 1);
		stage++;
		break ; // !BURASI SILINECEK
	}
}
