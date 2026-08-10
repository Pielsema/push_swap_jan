/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:09:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/29 18:36:19 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_lstsize_stack(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast_stack(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_stack **stack_a, t_bench *bench)
{
	if (rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	count_op(bench, OP_RA);
	return (0);
}

int	rb(t_stack **stack_b, t_bench *bench)
{
	if (rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	count_op(bench, OP_RB);
	return (0);
}

int	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	if (rotate(a) == -1 || rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rr", 1);
	count_op(bench, OP_RR);
	return (0);
}
