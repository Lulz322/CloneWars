/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_libft_funcs_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:27:08 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:10 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

int		pf_atoi(const char *s)
{
	long	i;
	int		sign;
	long	rv;

	rv = 0;
	i = 0;
	sign = 1;
	while ((s[i] == '\n') || (s[i] == '\t') || (s[i] == '\v') ||
			(s[i] == ' ') || (s[i] == '\f') || (s[i] == '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
		rv = ((rv * 10) + s[i++] - '0');
	return ((int)rv * sign);
}

int		pf_count_digits_uns(unsigned long long int n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		pf_count_digits_sgn(long long int n)
{
	int len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	pf_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ULLI	pf_pow(ULLI num, int times)
{
	while (times--)
		num *= 10;
	return (num);
}
