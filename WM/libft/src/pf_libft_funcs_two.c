/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_libft_funcs_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:27:16 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:18 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

void	pf_putchar(char c)
{
	write(1, &c, 1);
	g_i++;
}

void	pf_putstr(char const *s)
{
	unsigned int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		g_i++;
	}
}

void	pf_putnstr(const char *s, int len)
{
	unsigned int i;

	if (!s || len <= 0)
		return ;
	i = 0;
	while (s[i] && len--)
	{
		write(1, &s[i], 1);
		i++;
		g_i++;
	}
}

void	pf_putnbr_uns(unsigned long long int num)
{
	if (num > 9)
		pf_putnbr_uns(num / 10);
	pf_putchar((num % 10) + '0');
}

void	pf_putnbr_sgn(long long int n)
{
	unsigned long long int r;

	if (n < 0)
		r = (unsigned long long int)(n * -1);
	else
		r = (unsigned long long int)n;
	if (r > 9)
		pf_putnbr_sgn(r / 10);
	pf_putchar((r % 10) + '0');
}
