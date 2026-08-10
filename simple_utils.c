/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:19:35 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/30 22:41:14 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_generico(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;
	int	i;

	while (*a)
	{
		min_pos = find_min_pos(*a);
		size = ft_lstsize_stack(*a);
		if (min_pos <= size / 2)
			while (min_pos--)
				ra(a, bench);
		else
		{
			i = size - min_pos;
			while (i--)
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}

int	find_min_pos(t_stack *stack)
{
	int		i;
	int		min_pos;
	int		min_val;

	if (!stack)
		return (-1);
	i = 0;
	min_pos = 0;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack **a, t_bench *bench)
{
	int	pos;
	int	size;
	int	rotations;

	pos = find_min_pos(*a);
	size = ft_lstsize_stack(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a, bench);
	}
	else
	{
		rotations = size - pos;
		while (rotations-- > 0)
			rra(a, bench);
	}
}

int	is_almost_sorted(t_stack *a)
{
	int	count;

	count = 0;
	while (a && a->next)
	{
		if (a->value > a->next->value)
			count++;
		if (count > 1)
			return (0);
		a = a->next;
	}
	return (1);
}
