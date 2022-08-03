/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:59:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/08/03 17:35:40 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*addnode(t_stack *a, int number)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	new->index = 0;
	if (!a)
		return (new);
	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (a);
}

int	arginputcontrol(char *input, int *arg)
{
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
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	return (*arg);
}

/*
?	number A stack'inin icinde var mi diye bakar.
?	mod 0 ise numbernin stack icerisindeki sirasini return eder.
?	mod 0 degilse ve number stack icerisinde varsa 0 return eder.
*/
int	control(t_stack *a, int number, int mod)
{
	t_stack	*tmp;
	int		i;

	i = mod;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == number && mod == 0)
			return (i);
		if (tmp->number == number)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (i);
}
