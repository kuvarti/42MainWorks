/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PreapreTheSort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:11:18 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/05 12:10:56 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	c;

	c = *x;
	*x = *y;
	*y = c;
}

static void	quicksort(int number[], int first, int last)
{
	int	i;
	int	j;
	int	pivot;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (number[i] <= number[pivot] && i < last)
				i++;
			while (number[j] > number[pivot])
				j--;
			if (i < j)
				swap(&number[i], &number[j]);
		}
		swap(&number[pivot], &number[j]);
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);
	}
}

static int	*sirala(t_stack *a)
{
	int		gez;
	int		*index;
	t_stack	*tmp;

	gez = 0;
	tmp = a;
	while (tmp)
	{
		gez++;
		tmp = tmp->next;
	}
	index = ft_calloc(sizeof(int), gez + 1);
	gez = 0;
	tmp = a;
	while (tmp)
	{
		index[gez++] = tmp->sayi;
		tmp = tmp->next;
	}
	quicksort(index, 0, gez - 1);
	return (index);
}

t_stack	*minisort(t_stack *a)
{
	int		i;
	int		*index;
	t_stack	*tmp;

	index = sirala(a);
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (tmp->sayi != index[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free(index);
	return (a);
}
