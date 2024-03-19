/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoneValidation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:30:26 by aeryilma          #+#    #+#             */
/*   Updated: 2024/03/19 14:43:59 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	AppendZoneFront(t_zone *Node, t_zone *NewZone)
{
	t_zone *tmp;

	tmp = Node->prev;
	if (tmp != NULL) {
		tmp->next = NewZone;
		NewZone->prev = tmp;
		NewZone->next = Node;
		Node->prev = NewZone;
		if (NewZone->size < tmp->size)
			g_zones = NewZone;
	} else {
		NewZone->next = Node;
		NewZone->prev = Node;
		Node->next = NewZone;
		Node->prev = NewZone;
		g_zones = NewZone;
	}
}

void	AppendZoneBack(t_zone *Node, t_zone *NewZone)
{
	t_zone *tmp;

	tmp = Node->next;
	if (tmp != NULL) {
		tmp->prev = NewZone;
		NewZone->next = tmp;
		NewZone->prev = Node;
		Node->next = NewZone;
	} else {
		NewZone->next = Node;
		NewZone->prev = Node;
		Node->next = NewZone;
		Node->prev = NewZone;
	}
}
