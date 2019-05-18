/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:41:22 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/17 17:29:56 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	negto_pos(int a)
{
	if (a < -2147483647)
		a++;
	a = a * -1;
	write(1, "-", 1);
	return (a);
}

void		ft_putnbr(int n)
{
	int		i;
	char	buff[11];

	i = 0;
	if (n < 0)
	{
		if (n < -2147483647)
			i--;
		n = negto_pos(n);
	}
	while (n > 9)
	{
		if (i < 0)
			buff[++i] = (n % 10 + '0') + 1;
		else
			buff[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	buff[i] = n + '0';
	buff[++i] = '\0';
	while (i-- > 0)
		write(1, &buff[i], 1);
}
