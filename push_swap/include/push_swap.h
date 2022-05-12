/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeryilma <aeryilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:36:49 by aeryilma          #+#    #+#             */
/*   Updated: 2022/05/12 06:30:13 by aeryilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct s_stack
{
	int				sayi;
	struct s_stack	*next;
}	t_stack;

//OPERATIONS
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a);


int	inputkontrol(char *input, int *arg);
