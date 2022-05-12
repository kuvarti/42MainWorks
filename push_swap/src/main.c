/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:05:46 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/12 06:31:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->sayi = content;
	new->next = NULL;
	return (new);
}

t_stack	*ekle(t_stack *a, int sayi)
{
	t_stack	*tmp;

	if (!a)
		return (newstack(sayi));
	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = newstack(sayi);
	return (a);
}

int	kontrol(t_stack *a, int sayi)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->sayi == sayi)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
	int		gez;
	int		arg;

	gez = 0;
	a = 0;
	if (argc == 1)
		return (0);
	while (argv[++gez])
	{
		if (!inputkontrol(argv[gez], &arg))
			return (ft_printf("Error\n"));
		if (kontrol(a, arg))
			a = ekle(a, arg);
	}

	ss(&a);
	while (a)
	{
		ft_printf("%d", a->sayi);
		a = a->next;
		if (a)
			ft_printf(" - ");
		else
			ft_printf("\n");
	}
}
