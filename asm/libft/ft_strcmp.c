/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:56:39 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/11/05 21:56:42 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (cs1[i] != '\0' || cs2[i] != '\0')
	{
		if (cs1[i] > cs2[i])
			return (cs1[i] - cs2[i]);
		if (cs1[i] < cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
