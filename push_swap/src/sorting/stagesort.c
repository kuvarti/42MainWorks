/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stagesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/02 14:57:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! ITS NOT WORKING NOW

static int	smart_pusher(t_stack **a, t_stack **b, int min, int pivot)
{
	int	ret;
	int	i;

	ret = 1;
	i = kontrol(*b, pivot, 0);
	if (i < (pivot - min) + 1)
	{
		while (i--)
		{
			if ((*b)->index == pivot - 1 && ret++)
				pa(a, b);
			rb(b);
		}
	}
	else
	{
		i = stacklen(*b) - i;
		while (i--)
		{
			if ((*b)->index == pivot - 1 && ret++)
				pa(a, b);
			rrb(b);
		}
	}
	return (ret - 1);
}

static void	stage_sorter(t_stack **a, t_stack **b, int min, int max)
{
	int	i;
	int	j;

	j = 0;
	while (max >= min)
	{
		i = smart_pusher(a, b, min, max);
		pa(a, b);
		if (i)
			sa(a);
		max -= i + 1;
	}
}

static int	smart_swap(t_stack **a, t_stack **b, int max)
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
	if (alen >= 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if ((*a)->index > max && (*a)->next->index)
			r_n(a, b, 2, 'a');
		return (1);
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
			if (smart_swap(a, b, max) == 1)
				continue ;
			ra(a);
		}
		pb(a, b);
		max--;
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
