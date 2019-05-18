/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 12:22:47 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/02/05 12:22:55 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_numsort(int *numbers, size_t obj_num)
{
	size_t	i;
	int		aux;
	int		swapped;

	swapped = 1;
	if (!numbers || !obj_num)
		return (NULL);
	while (swapped && numbers && obj_num)
	{
		swapped = 0;
		i = 0;
		while (i < (obj_num - 1))
		{
			if (numbers[i] > numbers[i + 1])
			{
				swapped = 1;
				aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
			}
			i++;
		}
	}
	return (numbers);
}
