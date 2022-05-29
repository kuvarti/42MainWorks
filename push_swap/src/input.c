/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:59:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/26 11:55:18 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*newstack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->sayi = content;
	new->next = NULL;
	return (new);
}

static t_stack	*nodekle(t_stack *a, int sayi)
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

t_stack *ekle(char **argv)
{
	t_stack	*a;
	int		gez;
	int		arg;

	a = 0;
	gez = 0;
	while (argv[++gez])
	{
		if (!inputkontrol(argv[gez], &arg))
			exit(ft_printf("Error\n"));
		if (kontrol(a, arg))
			a = nodekle(a, arg);
	}
	return (a);
}

int	inputkontrol(char *input, int *arg)
{
	int	i;

	if (input[0] == '0' && !input[1])
	{
		*arg = 0;
		return (1);
	}
	if (input[0] == '-' && input[1] == '1' && !input[2])
	{
		*arg = -1;
		return (1);
	}
	i = 0;
	if (input[i] == '-')
		i++;
	while (input[i])
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (0);
		i++;
	}
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	return (*arg);
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
