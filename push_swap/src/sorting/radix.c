/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/05 15:40:55 by aeryilma         ###   ########.fr       */
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
			if (((*a)->index) >> otele & 1)	//TODO Fazladan aramasına engel olunabilinir
				ra(a);
			else
			{
				pb(a, b);
				continue ;
			}
		}
		otele++;
		if (!control(*a, otele) || !swipe(a, b, otele))
			break ;
	}
	while ((*b))
		pa(a, b);
}
