/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/27 19:10:55 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int	bits(t_stack *a, int otele)
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
*/
static void	terscevir(t_stack **a, t_stack **b)
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

static int	swipe(t_stack **a, t_stack **b)
{
	int	i;

	i = stacklen(*b);
	if (!i)
		return (0);
	while (i--)
	{
		pa(a, b);
	}
	return (1);
}

void	sortradix(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		otele;

	otele = 0;
	tmp = *a;
	while (otele <= 9)
	{
		i = stacklen(*a);
		while (i--)
		{
			if (((*a)->index) >> otele & 1)
			{
				pb(a, b);
				continue ;
			}
//			if (!bits(*a, otele))
//				break ;
			ra(a);
		}
		otele++;
		if (!swipe(a, b))
			break ;
	}
	terscevir(a, b);
}
