/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:26:28 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/18 15:30:04 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*gez;

	if (*lst == NULL)
		*lst = new;
	else
	{
		gez = ft_lstlast(*lst);
		gez -> next = new;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*liste = ft_lstnew((void *)49);
	t_list	*tut;

	for (size_t i = 50; i < 55; i++)
	{
		ft_lstadd_back(&liste, ft_lstnew((void *)i));
	}
	tut = ft_lstlast(liste);
	printf("%c", (char)(tut -> content));
}
*/
