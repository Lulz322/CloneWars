/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 19:36:59 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 20:47:27 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fs;
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		fs = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (fs == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			fs[i] = f(i, s[i]);
			i++;
		}
		fs[i] = '\0';
		return (fs);
	}
	return (NULL);
}
