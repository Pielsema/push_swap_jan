/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:57:26 by jsobotka          #+#    #+#             */
/*   Updated: 2026/07/02 18:12:07 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

void	sort_three(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

void	sort_four(t_stack **a, t_stack **b, t_bench *bench)
{
	if (sort_four_special(a, bench))
		return ;
	move_min_to_top(a, bench);
	pb(a, b, bench);
	sort_three(a, bench);
	pa(a, b, bench);
}

void	sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;

	while (ft_lstsize_stack(*a) > 3)
	{
		min_pos = find_min_pos(*a);
		if (min_pos <= ft_lstsize_stack(*a) / 2)
			while (min_pos--)
				ra(a, bench);
		else
		{
			size = ft_lstsize_stack(*a);
			while (size - min_pos++)
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = ft_lstsize_stack(*a);
	if (size == 2)
		return (sort_two(a, bench));
	if (size == 3)
		return (sort_three(a, bench));
	if (size == 4)
		return (sort_four(a, b, bench));
	if (size == 5)
		return (sort_five(a, b, bench));
	simple_generico(a, b, bench);
}
