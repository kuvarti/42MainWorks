/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/29 12:16:08 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int	!bits(t_stack *a, int otele)
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
} // * this is non return 0

static int	!swipe(t_stack **a, t_stack **b)
{
	int	i;

	i = stacklen(*b);
	if (!(i))
		return (0);
	while (i--)
	{
		pa(a, b);
	}
	return (1);
} // * This is non return 0
*/
// ! bunu kullaninca fazladan 256 islem yapiyor.
static int	swipe_and_control(t_stack **a, t_stack **b, int swipe)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = stacklen(*b);
	while (tmp)
	{
		if ((tmp->index) >> swipe & 1)
		{
			while (i--)
			{
				pa(a, b);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	i = stacklen(*b);
	if (!(i))
		return (0);
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

void	sortradix(t_stack **a, t_stack **b)
{
	int		i;
	int		otele;

	otele = 0;
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
			ra(a);
		}
		otele++;
		if (!swipe_and_control(a, b, otele))
			break ;
	}
	reverse(a, b);
}
