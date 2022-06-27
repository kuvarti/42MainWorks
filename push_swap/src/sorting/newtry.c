/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:12:58 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/26 02:28:37 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	besorted()

int	nerede(t_stack **b)
{
	int		status;
	int		uzaklik;
	t_stack	*tmp;

	status = 1;
	while (status)
	{
		status = 0;
		tmp = *b;
		uzaklik = 0;
		while (tmp->next)
		{
			uzaklik++;
			if (tmp->index > tmp->next->index)
			{
				// * Kalan yereküçük yeri sıralamadak kaldı
				status = 1;
			}
			tmp = tmp->next;
		}
	}
}

void	deneme(t_stack **a, t_stack **b)
{
	int	pivot;
	int	i;
	int	times;

	times = 1;
	i = stacklen(*a);
	pivot = i / 4;
	while (pivot <= stacklen(*a))
	{
		i = stacklen(*a);
		while (i)
		{
			if ((*a)->index < pivot)
				pb(a, b);
			else
				ra(a);
			i--;
		}
		nerede(b);
		i = stacklen(*b);
		while (i)
		{
			pa(a, b);
			i--;
		}
		times++;
		pivot = (stacklen(*a) / 4) * times;
	}
	printstack(*a, *b);
}
