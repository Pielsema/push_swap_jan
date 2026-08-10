/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:53:46 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/30 21:12:20 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	almost_sorted(t_stack **a, t_stack **b, t_bench *bench)
{
	(void)b;
	if (is_sorted(*a))
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
	if (!is_sorted(*a) && (*a)->next->next)
	{
		if ((*a)->next->value > (*a)->next->next->value)
		{
			ra(a, bench);
			sa(a, bench);
			rra(a, bench);
		}
	}
	if (!is_sorted(*a) && (*a)->value > (*a)->next->value)
		sa(a, bench);
}
