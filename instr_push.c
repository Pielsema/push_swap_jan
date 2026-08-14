/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:09:07 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/29 18:32:23 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **to, t_stack **from)
{
	t_stack	*tmp;

	if (!from || !*from)
		return (-1);
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	emit_op(bench, OP_PA);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	emit_op(bench, OP_PB);
	return (0);
}
