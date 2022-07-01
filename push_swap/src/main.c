/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:05:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/01 16:50:05 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ekle(char **argv, int argc, t_stack *a)
{
	int		gez;
	int		arg;

	gez = 0;
	if (argc > 2)
	{
		while (argv[++gez])
		{
			if (!arginputkontrol(argv[gez], &arg))
				exit(ft_printf("Error\n"));
			if (kontrol(a, arg, 1))
				a = nodekle(a, arg);
		}
	}
	else
	{
		while (argv[1][gez])
		{
			if (!strinputkontrol(&argv[1][gez], &arg, &gez))
				exit(ft_printf("Error\n"));
			if (kontrol(a, arg, 1))
				a = nodekle(a, arg);
		}
	}
	return (a);
}

void	printstack(t_stack *a, t_stack *b)
{
	ft_printf("a : ");
	while (a)
	{
		ft_printf("%d(%d)", a->sayi, a->index);
		a = a->next;
		if (a)
			ft_printf(" - ");
	}
	ft_printf("\nb : ");
	while (b)
	{
		ft_printf("%d(%d)", b->sayi, b->index);
		b = b->next;
		if (b)
			ft_printf(" - ");
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	a = ekle(argv, argc, a);
	a = minisort(a);
	if (stacklen(a) < 7)
		shortsort(&a, &b);
	else
		sort(&a, &b);
//	printstack(a, b);
}
