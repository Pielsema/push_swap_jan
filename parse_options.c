/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:35:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/08 12:35:00 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_options(int *argc, char ***argv, t_app *app)
{
	app->debug = parse_debug(argc, *argv);
	app->bench_enabled = parse_bench(argc, *argv);
	app->mode = parse_mode(argc, argv);
	app->debug |= parse_debug(argc, *argv);
	app->bench_enabled |= parse_bench(argc, *argv);
}
