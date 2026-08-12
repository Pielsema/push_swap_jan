/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pielsema <pielsema@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 14:27:59 by pielsema          #+#    #+#             */
/*   Updated: 2026/08/11 14:31:10 by pielsema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	i;

	dlen = 0;
	while (dlen < dstsize && dst[dlen])
		dlen++;
	if (dlen == dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] && dlen + i + 1 < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	if (dlen + i < dstsize)
		dst[dlen + i] = '\0';
	return (dlen + ft_strlen(src));
}
