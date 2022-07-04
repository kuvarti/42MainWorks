/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stagesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/04 17:35:49 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//! DIDNT WORK EXCELENT

int	smart_swap(t_stack **a, t_stack **b, int max)
{
	int	alen;
	int	blen;

	alen = stacklen(*a);
	blen = stacklen(*b);
	if (alen >= 2 && blen >= 2)
	{
		if ((*a)->index > (*a)->next->index && (*b)->index < (*b)->next->index)
		{
			ss(a, b);
			return (1);
		}
	}
	else if (alen >= 2)
	{
		if ((*a)->index > (*a)->next->index)
		{
			sa(a);
			return (1);
		}
		if ((*a)->index > max && (*a)->next->index > max)
		{
			r_n(a, b, 2, 'a');
			return (1);
		}
	}
	return (0);
}

static void	stage_pusher(t_stack **a, t_stack **b, int max)
{
	while (haspush(*a, &max))
	{
		while ((*a)->index != max)
		{
			if ((*a)->index <= max)
			{
				pb(a, b);
				continue ;
			}
			if (smart_swap(a, b, max))
				continue ;
			ra(a);
		}
		pb(a, b);
	}
}

void	stagesort(t_stack **a, t_stack **b)
{
	int	stage;
	int	index;
	int	max;

	max = stacklen(*a);
	stage = 1;
	while (stage <= 5)
	{
		index = (max / 5) * stage;
		stage_pusher(a, b, index - 1);
		stage_sorter(a, b, (max / 5) * (stage - 1), index - 1);
		stage++;
	}
	stage = stacklen(*b);
	pa(a, b);
	while (stage--)
	{
		pa(a, b);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
}
