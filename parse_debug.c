/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:12:00 by jsobotka          #+#    #+#             */
/*   Updated: 2026/08/16 15:12:48 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	remove_arg(int *argc, char **argv, int i)
{
	while (i < *argc - 1)
	{
		argv[i] = argv[i + 1];
		i++;
	}
	argv[i] = NULL;
	(*argc)--;
}

static int	parse_flag(int *argc, char **argv, char *flag)
{
	int	i;
	int	found;

	i = 1;
	found = 0;
	while (i < *argc)
	{
		if (!ft_strcmp(argv[i], flag))
		{
			found = 1;
			remove_arg(argc, argv, i);
		}
		else
			i++;
	}
	return (found);
}

int	parse_debug(int *argc, char **argv)
{
	return (parse_flag(argc, argv, "--debug"));
}

int	parse_bench(int *argc, char **argv)
{
	return (parse_flag(argc, argv, "--bench"));
}
