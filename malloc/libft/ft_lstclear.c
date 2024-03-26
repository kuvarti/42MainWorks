/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:23:27 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/26 16:41:19 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cup;

	tmp = *lst;
	while (tmp)
	{
		cup = tmp -> next;
		(*del)(tmp -> content);
		free(tmp);
		tmp = cup;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
void ft_del(void *content)
{
	bzero(content, sizeof(content));
}
int	main()
{
	char l[] = "start";
	char s0[] = "student0";
	char s1[] = "student1";
	char s2[] = "student2";
	t_list *lst = ft_lstnew(l);
	t_list *student0 = ft_lstnew(s0);
	t_list *student1 = ft_lstnew(s1);
	t_list *student2 = ft_lstnew(s2);

	ft_lstadd_back(&lst, student0);
	ft_lstadd_back(&lst, student1);
	ft_lstadd_back(&lst, student2);
	ft_lstclear(&lst, ft_del);
	while(lst)
	{
		printf("%s\n",(char *)lst->content);
		lst = lst->next;
	}
}
*/
