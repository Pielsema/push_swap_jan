#include "libft.h"

int	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}
