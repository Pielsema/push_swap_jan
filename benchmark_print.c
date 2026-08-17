/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:18:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/16 15:12:18 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*op_name(int op)
{
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	return ("rrr");
}

static void	print_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(value / 100, 2);
	ft_putchar_fd('.', 2);
	if (value % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putendl_fd("%", 2);
}

int	total_ops(t_bench *bench)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
		total += bench->ops[i++];
	return (total);
}

static void	print_op_counts(t_bench *bench)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		ft_putstr_fd("[bench] ", 2);
		ft_putstr_fd(op_name(i), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(bench->ops[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

void	print_bench(t_bench *bench)
{
	if (!bench->enabled)
		return ;
	print_disorder(bench->disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(bench->strategy, 2);
	ft_putstr_fd(" ", 2);
	ft_putendl_fd(bench->complexity, 2);
	ft_putstr_fd("[bench] total: ", 2);
	ft_putnbr_fd(total_ops(bench), 2);
	ft_putchar_fd('\n', 2);
	print_op_counts(bench);
}
