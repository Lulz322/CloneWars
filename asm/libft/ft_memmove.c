/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:13:06 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:13:12 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*csrc;
	char		*cdst;
	size_t		i;

	i = 0;
	csrc = src;
	cdst = dst;
	if (dst < src)
	{
		while (len--)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else
	{
		csrc = csrc + len;
		cdst = cdst + len;
		while (len--)
			*--cdst = *--csrc;
	}
	return (dst);
}
