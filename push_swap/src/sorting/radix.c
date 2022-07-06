/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/06 12:37:42 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control(t_stack *a, int otele)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if ((tmp->index) >> otele & 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	swipe(t_stack **a, t_stack **b, int swipe)
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

static int	issorted(t_stack *a, t_stack *b)
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
	int		otele;

	otele = 0;
	while (1)
	{
		i = stacklen(*a);
		while (i--)
		{
			if (((*a)->index) >> otele & 1)
				ra(a);
			else
			{
				pb(a, b);
				continue ;
			}
			if (!issorted(*a, *b))
				break ;
		}
		otele++;
		if (!issorted(*a, *b) || !control(*a, otele) || !swipe(a, b, otele))
			break ;
	}
	while ((*b))
		pa(a, b);
}
