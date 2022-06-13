/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:59:15 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/13 20:24:56 by aeryilma         ###   ########.fr       */
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

static int	ft_isspace(char chr)
{
	if (chr)
		if ((chr >= 9 && chr <= 13) || chr == ' ')
			return (1);
	return (0);
}

// LINE EKSILTT!!!
//FT_İSSPACEEEEEEEEE!!
int	strinputkontrol(char *input, int *arg, int *index)
{
	int	i;

	i = 0;
	while (ft_isspace(input[i]) && input[i])
		i++;
	if (input[i] == '0' && ft_isspace(input[i + 1]))
	{
		*arg = 0;
		(*index) += i + 1;
		return (1);
	}
	if (input[i] == '-' && input[i + 1] == '1' && ft_isspace(input[i + 2]))
	{
		*arg = -1;
		(*index) += i + 2;
		return (1);
	}
	*arg = ft_atoi(input);
	if (*arg == 0 || *arg == -1)
		return (0);
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	(*index) += i;
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
