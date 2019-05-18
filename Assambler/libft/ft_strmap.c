/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 21:05:14 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 20:49:32 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fs;
	size_t	i;

	i = 0;
	if (s != NULL)
	{
		fs = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (fs == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			fs[i] = f(s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
