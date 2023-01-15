/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 03:37:58 by aeryilma          #+#    #+#             */
/*   Updated: 2022/02/18 15:59:52 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = 0;
	while (lst)
	{
		tmp = ft_lstnew(f(lst -> content));
		if (!tmp)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, tmp);
		lst = lst -> next;
	}
	return (ret);
}
/*
#include <stdio.h>
void	sil(void *con)
{
	ft_bzero(con, sizeof(con));
}
void	*fa(void *content)
{
	content = content + 2;
	return (content);
}
int	main(void)
{
	t_list	*liste = ft_lstnew((void *)49);
	t_list	*tut;
	size_t	i;

	for (i = 50; i < 55; i++)
	{
		ft_lstadd_back(&liste, ft_lstnew((void *)i));
	}
	tut = ft_lstmap(liste, fa, sil);
	printf("liste :\n");
	for (i = 49; i < 55; i++)
	{
		printf("%c - ",(char)(liste -> content));
		liste = liste -> next;
	}
	printf("\nsonuc :\n");
	for (i = 49; i < 55; i++)
	{
		printf("%c - ",(char)(tut -> content));
		tut = tut -> next;
	}

}
*/
