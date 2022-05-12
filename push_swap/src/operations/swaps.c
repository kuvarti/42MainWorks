/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:03:17 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/12 06:31:15 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sx(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*cup;

	tmp = a->next;
	cup = tmp->next;
	tmp->next = a;
	a->next = cup;
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

void	ss(t_stack **a)
{
	*a = sx(*a);
	*a = sx(*a);
	ft_printf("ss\n");
}
