/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:24:43 by pielsema          #+#    #+#             */
/*   Updated: 2026/08/14 16:27:20 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*out;
	long	nb;
	int		len;

	nb = n;
	len = num_len(nb);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	if (nb < 0)
	{
		out[0] = '-';
		nb = -nb;
	}
	while (--len >= 0 && out[len] != '-')
	{
		out[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (out);
}
