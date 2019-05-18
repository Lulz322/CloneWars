/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:41:22 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/17 17:29:53 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	negto_pos_fd(int a, int fd)
{
	if (a < -2147483647)
		a++;
	a = a * -1;
	write(fd, "-", 1);
	return (a);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	buff[11];

	i = 0;
	if (n < 0)
	{
		if (n < -2147483647)
			i--;
		n = negto_pos_fd(n, fd);
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
		write(fd, &buff[i], 1);
}
