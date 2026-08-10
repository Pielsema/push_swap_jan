/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:10:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/05 15:10:00 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strategy(t_bench *bench, char *name, char *complexity)
{
	bench->strategy = name;
	bench->complexity = complexity;
}

void	init_bench(t_bench *bench, int enabled, int mode, t_stack *a)
{
	int	i;

	i = 0;
	bench->enabled = enabled;
	bench->disorder = compute_disorder(a);
	while (i < 11)
		bench->ops[i++] = 0;
	if (mode == SIMPLE || (mode == ADAPTIVE && bench->disorder < 0.2))
		set_strategy(bench, "simple", "O(n2)");
	else if (mode == MEDIUM || (mode == ADAPTIVE && bench->disorder < 0.5))
		set_strategy(bench, "medium", "O(n sqrt(n))");
	else if (mode == COMPLEX || mode == ADAPTIVE)
		set_strategy(bench, "complex", "O(n log n)");
	if (mode == ADAPTIVE)
		bench->strategy = "adaptive";
}

void	count_op(t_bench *bench, int op)
{
	if (bench && op >= 0 && op < 11)
		bench->ops[op]++;
}
