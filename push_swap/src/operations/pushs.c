/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:41:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/02 13:40:03 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pp(t_stack **x, t_stack **y)
{
	t_stack	*tmp;

	if (!(*y))
		return ;
	tmp = *y;
	*y = (*y)->next;
	(*tmp).next = *x;
	*x = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	pp(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	pp(b, a);
	ft_printf("pb\n");
}

void	p_n(t_stack **a, t_stack **b, int repeat, char mod)
{
	if (mod == 'a' || mod == 'A')
	{
		while (repeat--)
			pa(a, b);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (repeat--)
			pb(a, b);
	}
}
