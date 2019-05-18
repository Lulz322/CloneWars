/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:03:24 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/18 21:20:45 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	dlen;

	i = 0;
	j = 0;
	n = dstsize;
	while (n-- > 0 && dst[i] != '\0')
		i++;
	dlen = &dst[i] - &dst[0];
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (src[j] != '\0' && n-- != 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dlen + ft_strlen(src));
}
