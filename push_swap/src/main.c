/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:05:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/20 12:06:50 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	onlyspace(char *arg)
{
	int	gez;

	gez = 0;
	while (arg[gez] == ' ')
		gez++;
	if (!arg[gez])
		return (1);
	return (0);
}

// * Gez'i dışarıdan alma sebebim satır azaltmak
t_stack	*ekle(char **argv, int argc, t_stack *a, int gez)
{
	int		arg;

	if (argc > 2)
	{
		while (argv[++gez])
		{
			if (!arginputkontrol(argv[gez], &arg) || !kontrol(a, arg, 1))
				exit(ft_printf("Error\n"));
			a = nodekle(a, arg);
		}
	}
	else
	{
		while (argv[1][gez])
		{
			if (onlyspace(&argv[1][gez]))
				break ;
			if (!strinputkontrol(&argv[1][gez], &arg, &gez)
				|| !kontrol(a, arg, 1))
				exit(ft_printf("Error\n"));
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

static void	freestack(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*sil;

	tmp = a;
	while (tmp)
	{
		sil = tmp;
		tmp = tmp->next;
		free(sil);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = 0;
	b = 0;
	if (argc == 1)
		return (0);
	a = ekle(argv, argc, a, 0);
	a = minisort(a);
	len = stacklen(a);
	if (len < 7)
		shortsort(&a, &b);
	else
		sortradix(&a, &b);
	freestack(a);
	freestack(b);
}
