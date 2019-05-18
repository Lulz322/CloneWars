/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:58:03 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:12:35 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*buff_ldr(int num, int i, int j)
{
	char	*fs;
	char	buff[12];

	while (num > 9)
	{
		if (i < 0)
			buff[++i] = (num % 10 + '0') + 1;
		else
			buff[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	buff[i] = num + '0';
	if (j < 0)
		buff[++i] = '-';
	buff[++i] = '\0';
	fs = (char *)malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (fs == NULL)
		return (NULL);
	j = 0;
	while (i-- > 0)
		fs[j++] = buff[i];
	fs[j] = '\0';
	return (fs);
}

char		*ft_itoa(int n)
{
	int		save;
	int		flag;
	char	*str;

	flag = 0;
	save = n;
	if (n < 0)
	{
		if (n < -2147483647)
		{
			flag--;
			n++;
		}
		n = n * -1;
	}
	str = buff_ldr(n, flag, save);
	return (str);
}
