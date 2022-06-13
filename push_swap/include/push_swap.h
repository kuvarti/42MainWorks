/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:36:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/06/13 17:51:35 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_stack
{
	int				sayi;
	unsigned int	index;
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

//INPUTFUNCTIONS
t_stack	*nodekle(t_stack *a, int sayi);
int	kontrol(t_stack *a, int sayi);
int	arginputkontrol(char *input, int *arg);
int	strinputkontrol(char *input, int *arg, int *index);

//PREPARE
t_stack	*minisort(t_stack *a);

#endif
