/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:05:06 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:13:16 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	if (n > 0)
	{
		temp = (unsigned char*)b;
		while (0 < n)
		{
			temp[i] = (unsigned char)c;
			i++;
			n--;
		}
	}
	return (b);
}
