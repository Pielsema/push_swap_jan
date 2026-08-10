/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:00:25 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/30 22:50:12 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	chunk_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunk;
	int	i;

	size = ft_lstsize_stack(*a);
	chunk = sqrt(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + chunk)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
	while (*b)
		push_back(a, b, bench);
}

void	push_back(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = max_index(*b);
		pos = find_position(*b, max);
		size = ft_lstsize_stack(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max)
				rb(b, bench);
		}
		else
		{
			while ((*b)->index != max)
				rrb(b, bench);
		}
		pa(a, b, bench);
	}
}

int	find_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
