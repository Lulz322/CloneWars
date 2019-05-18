/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:57:20 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/17 17:32:42 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	*fin;

	cs = (unsigned char *)s;
	fin = cs + n;
	while (n-- && *cs != (unsigned char)c)
		cs++;
	if (fin <= cs)
		return (NULL);
	if (*cs == (unsigned char)c)
		return ((void *)cs);
	return (0);
}
