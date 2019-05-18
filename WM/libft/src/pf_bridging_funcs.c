/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bridging_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:26:16 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:26:23 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

int		pf_count_digits_base(ULLI num)
{
	int len;
	int base;

	len = 1;
	base = 10;
	if (g_s.id == 88 || g_s.id == 120 || g_s.id == 112)
		base = 16;
	else if (g_s.id == 111)
		base = 8;
	while (num >= (ULLI)base)
	{
		num /= base;
		len++;
	}
	return (len);
}

void	pf_putnbr_base_low(ULLI num, ULLI base)
{
	if (num >= base)
	{
		pf_putnbr_base_low(num / base, base);
	}
	write(1, &("0123456789abcdef"[num % base]), 1);
	g_i++;
}

void	pf_putnbr_base_up(ULLI num, ULLI base)
{
	if (num >= base)
	{
		pf_putnbr_base_up(num / base, base);
	}
	write(1, &("0123456789ABCDEF"[num % base]), 1);
	g_i++;
}

LLI		pf_get_value_sgn(va_list ap)
{
	if (g_s.hh == 1)
		return ((short int)va_arg(ap, int));
	if (g_s.hh == 2)
		return ((signed char)va_arg(ap, int));
	if (g_s.ll == 1)
		return (va_arg(ap, long int));
	if (g_s.ll == 2)
		return (va_arg(ap, LLI));
	return (va_arg(ap, int));
}

ULLI	pf_get_value_uns(va_list ap)
{
	if (g_s.hh == 1)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (g_s.hh == 2)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (g_s.ll == 1)
		return (va_arg(ap, unsigned long int));
	if (g_s.ll == 2)
		return (va_arg(ap, ULLI));
	return (va_arg(ap, unsigned int));
}
