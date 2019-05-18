/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:38:19 by mbiliaie          #+#    #+#             */
/*   Updated: 2017/12/13 15:19:09 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lim_mm(unsigned long long num, char c, int m)
{
	if (m < 0 && num >= 922337203685477580 && c >= 56)
		return (0);
	if (m == 0 && num >= 922337203685477580 && c >= 55)
		return (-1);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			m;

	i = 0;
	num = 0;
	m = 0;
	while (ft_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m--;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		if (ft_lim_mm(num, str[i], m) == 0 || ft_lim_mm(num, str[i], m) == -1)
			return (ft_lim_mm(num, str[i], m));
		num = num * 10 + str[i] - '0';
		i++;
	}
	if (m < 0)
		return (-num);
	return (num);
}
