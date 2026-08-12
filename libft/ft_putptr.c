/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:27:34 by pielsema          #+#    #+#             */
/*   Updated: 2026/08/11 14:31:46 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putptr_digits(unsigned long p)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (p >= 16)
		count += putptr_digits(p / 16);
	count += ft_putchar(base[p % 16]);
	return (count);
}

int	ft_putptr(unsigned long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + putptr_digits(p));
}
