/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:39:31 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:17:15 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		j;
	const char	*save;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] == needle[j])
		{
			if (needle[j + 1] == '\0')
			{
				save = &haystack[i - j];
				return ((char*)save);
			}
			i++;
			j++;
		}
		i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
