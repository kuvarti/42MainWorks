/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:05:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/01 19:45:12 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*index;

	index = 0;
	b = 0;
	if (argc == 1)
		return (0);
	a = ekle(argv, &index);
	quicksort();
/*	b = ekle(b, 5);
	b = ekle(b, 10);
	b = ekle(b, 15);
	b = ekle(b, 20);*/
//
//	Here IS Operations
//
	ft_printf("a : ");
	while (a)
	{
		ft_printf("%d", a->sayi);
		a = a->next;
		if (a)
			ft_printf(" - ");
		else
			ft_printf("\n");
	}
	ft_printf("b : ");
	while (b)
	{
		ft_printf("%d", b->sayi);
		b = b->next;
		if (b)
			ft_printf(" - ");
		else
			ft_printf("\n");
	}
}
