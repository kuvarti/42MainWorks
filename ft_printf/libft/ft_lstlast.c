/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:15:02 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/18 15:29:48 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*gez;

	if (!lst)
		return (NULL);
	gez = lst;
	while (gez -> next != NULL)
	{
		gez = gez -> next;
	}
	return (gez);
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
