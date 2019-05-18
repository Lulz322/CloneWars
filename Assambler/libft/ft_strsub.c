/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:21:45 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 19:41:57 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fs;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		fs = (char *)malloc(sizeof(char) * (len + 1));
		if (fs == NULL)
			return (NULL);
		while (*s && len > 0)
		{
			fs[i] = s[start];
			i++;
			start++;
			len--;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
