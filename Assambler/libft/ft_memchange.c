/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 10:57:12 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/02/05 10:57:14 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchange(void *ptr, size_t size)
{
	char *fs;

	fs = NULL;
	if (ptr == NULL)
	{
		fs = ft_memalloc(size);
		if (fs == NULL)
			return (NULL);
		return (fs);
	}
	if (size == 0 && ptr)
	{
		fs = ft_memalloc(size);
		free(ptr);
		return (fs);
	}
	fs = malloc(sizeof(*ptr) * size);
	if (fs == NULL)
		return (NULL);
	ft_memcpy(fs, ptr, size);
	free(ptr);
	ptr = fs;
	return (ptr);
}
