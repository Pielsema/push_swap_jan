/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:03:17 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/30 18:42:37 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_simple(char *arg)
{
	return (!ft_strcmp(arg, "--simple"));
}

static int	is_medium(char *arg)
{
	return (!ft_strcmp(arg, "--medium"));
}

static int	is_complex(char *arg)
{
	return (!ft_strcmp(arg, "--complex"));
}

static int	is_adaptive(char *arg)
{
	return (!ft_strcmp(arg, "--adaptive"));
}

int	parse_mode(int *argc, char ***argv)
{
	char	*arg;

	if (*argc < 2)
		return (ADAPTIVE);
	arg = (*argv)[1];
	if (is_simple(arg))
		return (*argv += 1, *argc -= 1, SIMPLE);
	if (is_medium(arg))
		return (*argv += 1, *argc -= 1, MEDIUM);
	if (is_complex(arg))
		return (*argv += 1, *argc -= 1, COMPLEX);
	if (is_adaptive(arg))
		return (*argv += 1, *argc -= 1, ADAPTIVE);
	return (ADAPTIVE);
}
