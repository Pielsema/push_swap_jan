/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobotka <jsobotka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:59:50 by jsobotka          #+#    #+#             */
/*   Updated: 2026/06/29 16:34:06 by jsobotka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_sign(char *str, int *i, long *limit)
{
	int		sign;

	sign = 1;
	*limit = 2147483647;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
			*limit = 2147483648;
		}
		(*i)++;
	}
	return (sign);
}

static int	ft_safe_atoi(char *str, int *out)
{
	long	nb;
	long	limit;
	int		sign;
	int		i;

	nb = 0;
	i = 0;
	sign = ft_parse_sign(str, &i, &limit);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || nb > (limit - (str[i] - '0')) / 10)
			return (0);
		nb = nb * 10 + (str[i++] - '0');
	}
	*out = (int)(nb * sign);
	return (1);
}

static int	ft_contains(int num, char **argv, int i)
{
	int	next;

	i++;
	while (argv[i])
	{
		if (ft_safe_atoi(argv[i], &next) && next == num)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	int		tmp;
	char	**args;

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
		if (!ft_safe_atoi(args[i], &tmp) || ft_contains(tmp, args, i))
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free_array(args);
}
