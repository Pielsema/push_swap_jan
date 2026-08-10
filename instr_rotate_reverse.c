/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate_reverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:11:27 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/29 18:37:57 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	prev = *stack;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_stack **stack_a, t_bench *bench)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	count_op(bench, OP_RRA);
	return (0);
}

int	rrb(t_stack **stack_b, t_bench *bench)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	count_op(bench, OP_RRB);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if ((ft_lstsize_stack(*stack_a) < 2) || (ft_lstsize_stack(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	count_op(bench, OP_RRR);
	return (0);
}
