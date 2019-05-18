/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:38:35 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:16:38 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while ((cs1[i] != '\0' || cs2[i] != '\0') && i < n)
	{
		if (cs1[i] > cs2[i])
			return (cs1[i] - cs2[i]);
		if (cs1[i] < cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
