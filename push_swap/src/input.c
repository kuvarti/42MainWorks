/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:59:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/04 17:29:41 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*nodekle(t_stack *a, int sayi)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->sayi = sayi;
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

int	arginputkontrol(char *input, int *arg)
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

static void	ilerle(char *input, int *i, int *index)
{
	if (input[*i] == '-' || input[*i] == '+')
		(*i)++;
	while (ft_isdigit(input[*i]))
		(*i)++;
	(*index) += *i;
}

int	strinputkontrol(char *input, int *arg, int *index)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]) && input[i])
		i++;
	if (!input[i] && (*index)++)
		return (1);
	if (input[i] == '0' && (ft_isspace(input[i + 1]) || !input[i + 1]))
	{
		*arg = 0;
		(*index) += i + 1;
		return (1);
	}
	if (input[i] == '-' && input[i + 1] == '1'
		&& (ft_isspace(input[i + 2]) || !input[i + 2]))
	{
		*arg = -1;
		(*index) += i + 2;
		return (1);
	}
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	ilerle(input, &i, index);
	return (*arg);
}

/*
?	sayi A stack'inin icinde var mi diye bakar.
?	mod 0 ise sayinin stack icerisindeki sirasini return eder.
?	mod 0 degilse ve sayi stack icerisinde varsa 0 return eder.
*/
int	kontrol(t_stack *a, int sayi, int mod)
{
	t_stack	*tmp;
	int		i;

	i = mod;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == sayi && mod == 0)
			return (i);
		if (tmp->sayi == sayi)
			exit(ft_printf("Error\n"));
		tmp = tmp->next;
		i++;
	}
	return (i);
}
