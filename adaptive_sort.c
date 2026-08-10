/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 18:48:19 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/30 22:26:58 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	if (ft_lstsize_stack(*a) <= 5)
	{
		simple_sort(a, b, bench);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		simple_sort(a, b, bench);
		return ;
	}
	if (disorder < 0.5)
	{
		chunk_sort(a, b, bench);
		return ;
	}
	radix_sort(a, b, bench);
}
