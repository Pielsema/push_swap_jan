/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 12:35:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/14 17:30:46 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_options(int *argc, char ***argv, t_options *options)
{
	options->debug = parse_debug(argc, *argv);
	options->bench = parse_bench(argc, *argv);
	options->mode = parse_mode(argc, argv);
	options->debug |= parse_debug(argc, *argv);
	options->bench |= parse_bench(argc, *argv);
}
