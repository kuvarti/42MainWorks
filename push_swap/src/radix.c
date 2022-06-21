/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:32:35 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/21 20:38:04 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortradix(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		otele;

	otele = 0;
	tmp = *a;
	while (otele < 8)
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
		i = stacklen(*b);
		otele++;
		if (!i)
			break ;
		while (i--)
		{
			pa(a, b);
		}
	}
	i = stacklen(*a);
	while (i--)
	{
		rra(a);
		pb(a, b);
	}
	i = stacklen(*b);
	while (i--)
	{
		pa(a, b);
	}
}
