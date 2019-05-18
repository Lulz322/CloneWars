/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:09:49 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 19:47:13 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace_mx(char c)
{
	if (c == 32 || c == '\n' || c == '\t' || c == '\0')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*fs;

	i = 0;
	if (s != NULL)
	{
		while (isspace_mx(s[i]) && *s)
			i++;
		j = ft_strlen(s);
		while (isspace_mx(s[j]) && j > i)
			j--;
		fs = ft_strnew((ft_strlen(s) - i) - (ft_strlen(s) - j) + 1);
		if (fs == NULL)
			return (NULL);
		fs = ft_strncpy(fs, s + i, (ft_strlen(s) - i) - (ft_strlen(s) - j) + 1);
		return (fs);
	}
	return (NULL);
}
