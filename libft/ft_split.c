#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static void	free_split(char **out, size_t used)
{
	while (used)
		free(out[--used]);
	free(out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	out = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (len)
		{
			out[i] = ft_substr(s, 0, len);
			if (!out[i])
				return (free_split(out, i), NULL);
			i++;
		}
		s += len;
	}
	return (out);
}
