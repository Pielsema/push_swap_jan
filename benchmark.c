/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:10:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/16 15:12:28 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strategy(t_bench *bench, char *name, char *complexity)
{
	bench->strategy = name;
	bench->complexity = complexity;
}

void	init_bench(t_bench *bench, t_options *options, t_stack *a)
{
	int	i;

	i = 0;
	bench->enabled = options->bench;
	bench->disorder = compute_disorder(a);
	while (i < 11)
		bench->ops[i++] = 0;
	if (options->mode == SIMPLE
		|| (options->mode == ADAPTIVE && bench->disorder < 0.2))
		set_strategy(bench, "simple", "O(n2)");
	else if (options->mode == MEDIUM
		|| (options->mode == ADAPTIVE && bench->disorder < 0.5))
		set_strategy(bench, "medium", "O(n sqrt(n))");
	else if (options->mode == COMPLEX || options->mode == ADAPTIVE)
		set_strategy(bench, "complex", "O(n log n)");
	if (options->mode == ADAPTIVE)
		bench->strategy = "adaptive";
}

void	count_op(t_bench *bench, int op)
{
	if (bench && op >= 0 && op < 11)
		bench->ops[op]++;
}

void	emit_op(t_bench *bench, int op)
{
	ft_putendl_fd(op_name(op), 1);
	count_op(bench, op);
}
