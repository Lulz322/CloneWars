/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 08:54:03 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 20:55:08 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mp;

	mp = (char*)malloc(sizeof(char) * size);
	if (mp == NULL)
		return (NULL);
	ft_memset(mp, '\0', size);
	return (mp);
}
