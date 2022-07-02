/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortutilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:54:31 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/02 11:50:11 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	*get_stackindexes(t_stack *a)
{
	t_stack	*tmp;
	int		*ret;
	int		i;

	ret = ft_calloc(sizeof(int), stacklen(a) + 1);
	tmp = a;
	i = 0;
	while (tmp)
	{
		ret[i++] = tmp->index;
		tmp = tmp->next;
	}
	return (ret);
}

int	haspush(t_stack *a, int *pivot)
{
	t_stack	*tmp;
	int		max;

	max = 0;
	tmp = a;
	while (tmp)
	{
		if ((tmp->index > max) && (tmp->index <= *pivot))
			max = tmp->index;
		tmp = tmp->next;
	}
	if (!max)
		return (0);
	*pivot = max;
	return (1);
}
