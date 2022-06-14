/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:41:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/14 15:35:46 by aeryilma         ###   ########.fr       */
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
