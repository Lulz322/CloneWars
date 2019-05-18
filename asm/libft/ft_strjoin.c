/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:38:25 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/03/11 16:41:12 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*fs;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		fs = (char *)malloc(sizeof(*fs) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (fs == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			fs[i] = s1[i];
			i++;
		}
		while (*s2 != '\0')
		{
			fs[i] = *s2;
			i++;
			s2++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
