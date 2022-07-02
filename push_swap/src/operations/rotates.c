/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:35:20 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/02 12:10:06 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rx(t_stack **x)
{
	t_stack	*gez;
	t_stack	*tmp;

	if (!x)
		return ;
	gez = *x;
	tmp = *x;
	while (gez->next)
		gez = gez->next;
	gez->next = tmp;
	*x = (*x)->next;
	tmp ->next = NULL;
}

void	ra(t_stack **a)
{
	rx(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rx(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rx(a);
	rx(b);
	ft_printf("rr\n");
}

void	r_n(t_stack **a, t_stack **b, int repeat, char mod)
{
	if (mod == 'a' || mod == 'A')
	{
		while (repeat--)
			ra(a);
	}
	else if (mod == 'b' || mod == 'B')
	{
		while (repeat--)
			rb(b);
	}
	else if (mod == 'r' || mod == 'R')
	{
		while (repeat--)
			rr(a, b);
	}
}
