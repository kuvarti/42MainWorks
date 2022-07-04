/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/04 15:55:14 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	control(t_stack *a, int otele)
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
			rb(b);
		else
			pa(a, b);
	}
	return (1);
}

static void	reverse(t_stack **a, t_stack **b)
{
	int	i;

	i = stacklen(*a);
	while (i--)
	{
		pb(a, b);
	}
	i = stacklen(*b);
	while (i--)
	{
		rrb(b);
		pa(a, b);
	}
}

// TODO ters siralamayi cozersen 4 puan alinabilir
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
			{
				pb(a, b);
				continue ;
			}
			ra(a);
		}
		otele++;
		if (!control(*a, otele) || !swipe(a, b, otele))
			break ;
	}
	reverse(a, b);
}
