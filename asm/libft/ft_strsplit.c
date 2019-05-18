/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:58:39 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 19:27:44 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrd_cnt(const char *s, char c)
{
	size_t	i;
	size_t	num_wrd;
	int		midw;

	i = 0;
	num_wrd = 0;
	midw = 0;
	while (s[i])
	{
		if (midw == 0 && s[i] != c && s[i] != '\0')
			midw = 1;
		if (midw == 1 && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			midw = 0;
			num_wrd++;
		}
		i++;
	}
	return (num_wrd);
}

static int	ft_ltr_cnt(const char *s, char c)
{
	size_t i;
	size_t num_ltr;

	i = 0;
	num_ltr = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		num_ltr++;
		i++;
	}
	return (num_ltr);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**fs;
	size_t	num_wrd;

	i = 0;
	if (s != NULL)
	{
		num_wrd = ft_wrd_cnt(s, c);
		fs = (char **)malloc(sizeof(char *) * num_wrd + 1);
		if (fs == NULL)
			return (NULL);
		while (num_wrd--)
		{
			while (*s != '\0' && *s == c)
				s++;
			fs[i] = ft_strsub(s, 0, ft_ltr_cnt(s, c));
			if (fs[i] == NULL)
				return (NULL);
			s = s + ft_ltr_cnt(s, c);
			i++;
		}
		fs[i] = NULL;
		return (fs);
	}
	return (NULL);
}
