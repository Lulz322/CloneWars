/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:11:39 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 19:49:58 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *mp;

	mp = (char*)malloc(sizeof(char) * (size + 1));
	if (mp == NULL)
		return (NULL);
	ft_memset(mp, '\0', size + 1);
	return (mp);
}
