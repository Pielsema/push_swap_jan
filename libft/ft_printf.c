/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:27:16 by pielsema          #+#    #+#             */
/*   Updated: 2026/08/11 14:31:51 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arg(char spec, va_list args)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (spec == 'p')
		return (ft_putptr((unsigned long)va_arg(args, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (spec == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	if (spec == 'X')
		return (ft_puthexup(va_arg(args, unsigned int)));
	if (spec == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(spec));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
			count += print_arg(*++format, args);
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
