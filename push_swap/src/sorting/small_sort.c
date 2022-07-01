/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:13:11 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/01 15:26:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ucluolsun_gucluolsun(t_stack **a)
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

static void	ayir(t_stack **a, t_stack **b, int max, int i)
{
	while (i)
	{
		if ((*a)->index == max)
		{
			pb(a, b);
			max--;
			i--;
			continue ;
		}
		if ((*a)->index > (*a)->next->index)
			sa(a);
		if ((stacklen(*a) / 2) < kontrol(*a, max, 0))
			rra(a);
		else
			ra(a);
	}
}

static void	undersix(t_stack **a, t_stack **b, int len)
{
	int	i;

	ayir(a, b, len - 1, len - 3);
	if (len == 4 || len == 5)
		ucluolsun_gucluolsun(a);
	else if (len == 6)
	{
		ucluolsun_gucluolsun(a);
		ucluolsun_gucluolsun(b);
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
	int	i;

	i = stacklen(*a);
	if (i == 2)
	{
		if ((*a)->index == 1)
			sa(a);
	}
	if (i == 3)
		ucluolsun_gucluolsun(a);
	else
		undersix(a, b, i);
}
