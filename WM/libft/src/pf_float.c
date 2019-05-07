/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:26:41 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:26:43 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

static	long double	pf_radix_pow(long double ld, int times)
{
	while (times--)
		ld *= 0.1;
	return (ld);
}

static	void		pf_print_f_id_zero(void)
{
	if (!g_s.zp && ++g_i)
	{
		write(1, ".", 1);
		while ((g_s.pr)-- && ++g_i)
			write(1, "0", 1);
	}
}

static	void		pf_print_f_id_g_sms(ULLI left, ULLI right, char sign)
{
	if (sign && ++g_i)
		write(1, &sign, 1);
	pf_putnbr_base_low(left, 10);
	if (right == 0)
		pf_print_f_id_zero();
	else if (!g_s.zp && ++g_i)
	{
		write(1, ".", 1);
		pf_putnbr_base_low(right, 10);
	}
	else if (g_s.hs && ++g_i)
		write(1, ".", 1);
	while ((g_s.wd)-- > 0 && ++g_i)
		write(1, " ", 1);
}

static	void		pf_print_f_id(ULLI left, ULLI right, char sign)
{
	char c;

	c = (g_s.zr) ? '0' : ' ';
	if (c == '0' && sign && ++g_i)
		write(1, &sign, 1);
	while ((g_s.wd)-- > 0 && ++g_i)
		write(1, &c, 1);
	if (c == ' ' && sign && ++g_i)
		write(1, &sign, 1);
	pf_putnbr_base_low(left, 10);
	if (right == 0)
		pf_print_f_id_zero();
	else if (!g_s.zp && ++g_i)
	{
		write(1, ".", 1);
		pf_putnbr_base_low(right, 10);
	}
	else if (g_s.hs && ++g_i)
		write(1, ".", 1);
}

void				pf_f_identifier(va_list ap)
{
	long double	ld;
	char		sign;
	ULLI		left;
	ULLI		right;

	g_s.pr = (!g_s.zp && (g_s.pr <= 0)) ? 6 : g_s.pr;
	ld = (g_s.ul) ? va_arg(ap, long double) : va_arg(ap, double);
	sign = '\0';
	if (ld < 0)
		sign = '-';
	else if (g_s.ps && ld >= 0)
		sign = '+';
	else if (g_s.sp && ld >= 0)
		sign = ' ';
	ld *= (ld < 0) ? (-1) : 1;
	ld += (ld) ? pf_radix_pow(5, (g_s.pr + 1)) : 0;
	left = (ULLI)ld;
	right = (ld - (long double)left) * pf_pow(1, g_s.pr);
	g_s.wd -= (pf_count_digits_uns(left) + (sign != '\0'));
	g_s.wd -= (g_s.zp) ? 0 : g_s.pr;
	g_s.wd -= (g_s.hs || (!g_s.zp)) ? 1 : 0;
	if (g_s.ms)
		pf_print_f_id_g_sms(left, right, sign);
	else
		pf_print_f_id(left, right, sign);
}
