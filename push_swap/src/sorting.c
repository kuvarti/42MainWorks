/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:24:33 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/14 19:55:00 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define SAG 1
#define SOL -1

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

static void	go(t_stack **a, t_stack **b, int direction, int unit)
{
	if (direction == SAG)
	{
		while (unit--)
		{
			rra(a);
		}
	}
	else
	{
		while (unit--)
		{
			ra(a);
		}
	}
	pb(a, b);
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
			go(a, b, SAG, max - fark);
		else
			go(a, b, SOL, fark);
		index++;
	}
	while (i--)
		pa(a, b);
}
