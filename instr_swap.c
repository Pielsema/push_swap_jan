/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:08:28 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/29 18:39:25 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_stack **stack_a, t_bench *bench)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	count_op(bench, OP_SA);
	return (0);
}

int	sb(t_stack **stack_b, t_bench *bench)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	count_op(bench, OP_SB);
	return (0);
}

int	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	if (swap(a) == -1 || swap(b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	count_op(bench, OP_SS);
	return (0);
}
