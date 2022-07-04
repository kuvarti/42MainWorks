/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stagesorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:01:59 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/04 17:27:01 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smart_sorter(t_stack **a, t_stack **b, int min, int pivot)
{
	int	ret;
	int	i;

	ret = 1;
	i = kontrol(*b, pivot, 0);
	if (i < (pivot - min) + 1)
	{
		while (i--)
		{
			if ((*b)->index == (pivot - 1) && ret++)
				pa(a, b);
			else
				rb(b);
		}
	}
	else
	{
		i = stacklen(*b) - i;
		while (i--)
		{
			if ((*b)->index == (pivot - 1) && ret++)
				pa(a, b);
			rrb(b);
		}
	}
	return (ret - 1);
	a = b; //!!!!!!!!!!
}

static int	smart_firstsorter(t_stack **a, t_stack **b, int pivot)
{
	int	ret;
	int	i;

	ret = 1;
	i = kontrol(*b, pivot, 0);
	if (i < (pivot / 2) + 1)
	{
		while (i--)
		{
			if ((*b)->index == (pivot - 1))
				pa(a, b);
			else
				rb(b);
		}
	}
	else
	{
		i = stacklen(*b) - i;
		while (i--)
		{
			if ((*b)->index == (pivot - 1))
				pa(a, b);
			rrb(b);
		}
	}
	return (ret - 1);
	a = b;// !!!!!!!!!
}

void	stage_sorter(t_stack **a, t_stack **b, int min, int max)
{
	int	i;
	int	j;

	while (max >= min)
	{
		if (!min)
			i = smart_firstsorter(a, b, max);
		else
			i = smart_sorter(a, b, min, max);
		pa(a, b);
		j = stacklen(*a);
		if (j >= 2)
		{
			if ((*a)->index > (*a)->next->index)
				sa(a);
		}
		max -= i + 1;
	}
}
