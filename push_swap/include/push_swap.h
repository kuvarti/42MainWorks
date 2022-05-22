/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:36:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/21 14:37:26 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf.h"

typedef struct s_stack
{
	int				sayi;
	struct s_stack	*next;
}	t_stack;

//OPERATIONS
//SWAP
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//ROTATE
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
//REVERSEROTATE
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
//PUSH
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

int	inputkontrol(char *input, int *arg);

#endif
