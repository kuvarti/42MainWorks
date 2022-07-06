/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:36:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/07/06 12:34:47 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct s_stack
{
	int				sayi;
	int				index;
	struct s_stack	*next;
}	t_stack;

//OPERATIONS
//SWAP (0) <-> (1)
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//ROTATE (0) -> (-1)
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	r_n(t_stack **a, t_stack **b, int repeat, char mod);
//REVERSEROTATE (-1) -> (0)
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr_n(t_stack **a, t_stack **b, int repeat, char mod);
//PUSH	pa = B(0) --> A(0)
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	p_n(t_stack **a, t_stack **b, int repeat, char mod);

//INPUTFUNCTIONS
t_stack	*nodekle(t_stack *a, int sayi);
int		kontrol(t_stack *a, int sayi, int mod);
int		arginputkontrol(char *input, int *arg);
int		strinputkontrol(char *input, int *arg, int *index);

//GENERAL
t_stack	*minisort(t_stack *a);
void	printstack(t_stack *a, t_stack *b);

//SORTING UTILITIES
int		stacklen(t_stack *a);
int		get_minindex(t_stack *a);
int		*get_stackindexes(t_stack *a);
int		haspush(t_stack *a, int *pivot);
int		smart_swap(t_stack **a, t_stack **b, int max);
void	stage_sorter(t_stack **a, t_stack **b, int min, int max);

//SORTING ALGORITHMS
void	stagesort(t_stack **a, t_stack **b);
void	shortsort(t_stack **a, t_stack **b);
void	sortradix(t_stack **a, t_stack **b);

#endif
