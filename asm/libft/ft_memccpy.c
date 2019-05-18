/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:17:27 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:12:48 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	i = 0;
	while (0 < n)
	{
		if (csrc[i] == (char)c)
		{
			cdst[i] = csrc[i];
			break ;
		}
		cdst[i] = csrc[i];
		i++;
		n--;
	}
	if (n == 0)
		return (NULL);
	return (&cdst[i + 1]);
}
