#include "libft.h"

int	ft_puthexup(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthexup(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
