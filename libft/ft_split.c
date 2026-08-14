/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:25:26 by pielsema          #+#    #+#             */
/*   Updated: 2026/08/14 16:27:20 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	add_word(char **out, char const **s, char c, size_t *i)
{
	size_t	len;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	if (!len)
		return (1);
	out[*i] = ft_substr(*s, 0, len);
	if (!out[*i])
		return (0);
	(*i)++;
	*s += len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;

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
		if (!add_word(out, &s, c, &i))
			return (free_split(out, i), NULL);
	}
	return (out);
}
