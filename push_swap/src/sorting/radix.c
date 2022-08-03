/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/02 13:28:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//! bit control
int	b_control(t_stack *a, int swipe)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if ((tmp->index) >> swipe & 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

//! reverse push
static int	r_push(t_stack **a, t_stack **b, int swipe)
{
	int	i;

	i = stacklen(*b);
	if (!(i))
		return (0);
	while (i--)
	{
		if ((*b)->index >> (swipe) & 1)
			pa(a, b);
		else
			rb(b);
	}
	return (1);
}

int	issorted(t_stack *a, t_stack *b)
{
	int		index;
	t_stack	*tmp;

	tmp = a;
	index = a->index;
	while (tmp)
	{
		if (index > tmp->index)
			return (1);
		index = tmp->index;
		tmp = tmp->next;
	}
	if (!b)
		return (0);
	tmp = b;
	index = b->index;
	while (tmp)
	{
		if (index < tmp->index)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sortradix(t_stack **a, t_stack **b)
{
	int		i;
	int		swipe;

	swipe = 0;
	while (1)
	{
		i = stacklen(*a);
		while (i--)
		{
			if (((*a)->index) >> swipe & 1)
				ra(a);
			else
			{
				pb(a, b);
				continue ;
			}
			if (!issorted(*a, *b))
				break ;
		}
		swipe++;
		if (!issorted(*a, *b) || !b_control(*a, swipe) || !r_push(a, b, swipe))
			break ;
	}
	while ((*b))
		pa(a, b);
}
