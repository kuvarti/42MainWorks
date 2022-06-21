/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/17 21:42:36 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stacklen(t_stack *a)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = a;
	while (tmp)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

static void	go(t_stack **a, t_stack **b, int unit, int *index)
{
	int i;

	i = 0;
	if (unit > 0)
	{
		while (unit--)
		{
			if ((*a)->index == (*index) + 1)
			{
				pb(a, b);
				i++;
			}
			rra(a);
		}
	}
	else
	{
		unit *= -1;
		while (unit--)
		{
			if ((*a)->index == (*index) + 1)
			{
				pb(a, b);
				i++;
			}
			ra(a);
		}
	}
	pb(a, b);
	if (i)
	{
		sb(b);
		(*index)++;
	}
	(*index)++;
}

void	sort(t_stack **a, t_stack **b)
{
	int	index;
	int	fark;
	int	max;
	int	i;

	index = 0;
	i = stacklen(*a);
	while (index < i)
	{
		max = stacklen(*a);
		fark = kontrol(*a, index, 0);
		if (fark > (index / 2))
			go(a, b, max - fark, &index);
		else
			go(a, b, fark * -1, &index);
	}
	while (i--)
		pa(a, b);
}
