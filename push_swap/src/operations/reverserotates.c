/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:11:14 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/06 12:34:38 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrx(t_stack **x)
{
	t_stack	*gez;
	t_stack	*tmp;
	t_stack	*son;

	gez = *x;
	tmp = *x;
	if (!x || !(gez->next))
		return ;
	while (gez->next)
	{
		son = gez;
		gez = gez->next;
	}
	son->next = 0;
	gez->next = tmp;
	*x = gez;
}

void	rra(t_stack **a)
{
	rrx(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rrx(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rrx(a);
	rrx(b);
	ft_printf("rrr\n");
}

void	rr_n(t_stack **a, t_stack **b, int repeat, char mod)
{
	if (mod == 'a' || mod == 'A')
	{
		while (repeat--)
			rra(a);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (repeat--)
			rrb(b);
	}
	else if (mod == 'r' || mod == 'R')
	{
		while (repeat--)
			rrr(a, b);
	}
}
