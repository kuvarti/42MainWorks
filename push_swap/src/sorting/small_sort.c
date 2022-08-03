/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:13:11 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/03 17:37:31 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	triple_sort(t_stack **a)
{
	int	*i;

	i = get_stackindexes(*a);
	if (i[0] > i[1] && i[1] < i[2] && i[2] > i[0])
		sa(a);
	else if (i[0] < i[1] && i[0] > i[2] && i[2] < i[1])
		rra(a);
	else if (i[0] > i[1] && i[0] > i[2] && i[2] > i[1])
		ra(a);
	else if (i[0] < i[1] && i[0] < i[2] && i[2] < i[1])
	{
		sa(a);
		ra(a);
	}
	else if (i[0] > i[1] && i[0] > i[2] && i[2] < i[1])
	{
		sa(a);
		rra(a);
	}
}

static void	to_seperate(t_stack **a, t_stack **b, int max, int len)
{
	while (len)
	{
		if ((*a)->index == max)
		{
			pb(a, b);
			max--;
			len--;
			continue ;
		}
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if ((stacklen(*a) / 2) < control(*a, max, 0))
			rra(a);
		else
			ra(a);
	}
}

static void	undersix(t_stack **a, t_stack **b, int len)
{
	int	i;

	to_seperate(a, b, len - 1, len - 3);
	if (len == 4 || len == 5)
		triple_sort(a);
	else if (len == 6)
	{
		triple_sort(a);
		triple_sort(b);
	}
	i = stacklen(*b);
	while (i--)
	{
		pa(a, b);
		ra(a);
	}
}

void	shortsort(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	if (len == 2)
	{
		if ((*a)->index == 1)
			sa(a);
	}
	if (len == 3)
		triple_sort(a);
	else
		undersix(a, b, len);
}
