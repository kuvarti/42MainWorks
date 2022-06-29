/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:12:58 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/29 13:04:38 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	firstpush(t_stack **a, t_stack **b, int stage)
{
	t_stack	*tmp;
	int		i;

	b--;
	i = 0;
	tmp = *a;
	while (1)
	{
		while (tmp)
		{
			i++;
			if (tmp->index < stage)
				break;
			tmp = tmp->next;
		}
		if (i == stacklen(*a))
			break ;
	}
}

void	equal100(t_stack **a, t_stack **b)
{
	int	pivot;
	int	times;

	pivot = stacklen(*a);
	times = 5;
	while (times > 0)
	{
		b--;
		times--;
	}
}
