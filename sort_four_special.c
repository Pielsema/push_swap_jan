/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_special.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:35:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/08 12:35:00 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_case_a(t_stack *a)
{
	return (a->index == 2 && a->next->index == 1
		&& a->next->next->index == 0
		&& a->next->next->next->index == 3);
}

static int	is_case_b(t_stack *a)
{
	return (a->index == 3 && a->next->index == 2
		&& a->next->next->index == 0
		&& a->next->next->next->index == 1);
}

int	sort_four_special(t_stack **a, t_bench *bench)
{
	if (is_case_a(*a))
	{
		sa(a, bench);
		ra(a, bench);
		sa(a, bench);
		rra(a, bench);
		sa(a, bench);
		return (1);
	}
	if (is_case_b(*a))
	{
		sa(a, bench);
		ra(a, bench);
		ra(a, bench);
		return (1);
	}
	return (0);
}
