/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:03:17 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/21 23:17:06 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*sx(t_stack *x)
{
	t_stack	*tmp;
	t_stack	*cup;

	if (!x || !(x->next))
		return (x);
	tmp = x->next;
	cup = tmp->next;
	tmp->next = x;
	x->next = cup;
	return (tmp);
}

void	sa(t_stack **a)
{
	*a = sx(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	*b = sx(*b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	*a = sx(*a);
	*b = sx(*b);
	ft_printf("ss\n");
}
