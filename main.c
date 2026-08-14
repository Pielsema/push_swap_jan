/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:55:53 by jsobotka          #+#    #+#             */
/*   Updated: 2026/07/02 18:06:58 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	debug_print_stacks(t_stack *a, t_stack *b)
{
	ft_putendl_fd("STACK A:", 2);
	print_stack(a, 2);
	ft_putendl_fd("STACK B:", 2);
	print_stack(b, 2);
}

static void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	if (!args || !args[i])
		ft_error("Error");
	while (args[i])
	{
		new = ft_lstnew_stack(ft_atoi(args[i]));
		if (!new)
			stack_alloc_error(stack, args, argc);
		ft_lstadd_back_stack(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free_array(args);
}

void	sort_stack(t_stack **a, t_stack **b, int mode, t_bench *bench)
{
	if (mode == SIMPLE)
	{
		simple_sort(a, b, bench);
		return ;
	}
	if (mode == MEDIUM)
	{
		chunk_sort(a, b, bench);
		return ;
	}
	if (mode == COMPLEX)
	{
		radix_sort(a, b, bench);
		return ;
	}
	adaptive_sort(a, b, bench);
}

static int	run_app(t_app *app)
{
	if (is_sorted(app->a))
	{
		print_bench(&app->bench);
		if (app->options.debug)
			debug_print_stacks(app->a, app->b);
		free_stack(&app->a);
		return (0);
	}
	sort_stack(&app->a, &app->b, app->options.mode, &app->bench);
	print_bench(&app->bench);
	if (app->options.debug)
		debug_print_stacks(app->a, app->b);
	free_stack(&app->a);
	free_stack(&app->b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc < 2)
		return (0);
	parse_options(&argc, &argv, &app.options);
	ft_check_args(argc, argv);
	app.a = NULL;
	app.b = NULL;
	init_stack(&app.a, argc, argv);
	init_bench(&app.bench, &app.options, app.a);
	return (run_app(&app));
}
