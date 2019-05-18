/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:29:46 by iruban            #+#    #+#             */
/*   Updated: 2018/11/05 12:29:47 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int a, int b)
{
	int c;

	c = a;
	if (a)
	{
		if (b < 0)
			return (0);
		if (b == 0)
			return (1);
		while (--b)
			a = c * a;
		return (a);
	}
	return (0);
}