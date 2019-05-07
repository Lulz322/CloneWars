/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:27:43 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:46 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

static	void	pf_print_upperx_id(unsigned long long int num, char wdc)
{
	if (g_s.ms)
	{
		if (!g_s.ll && !g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0X", 2);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_base_up(num, 16);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
	{
		if (g_s.zr && !g_s.ll && !g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0X", 2);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		if (!g_s.zr && !g_s.ll && !g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0X", 2);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_base_up(num, 16);
	}
}

static	void	pf_print_lowerx_id(unsigned long long int num, char wdc)
{
	if (g_s.ms)
	{
		if (!g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0x", 2);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_base_low(num, 16);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
	{
		if (g_s.zr && !g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0x", 2);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		if (!g_s.zr && !g_s.hh && g_s.hs && num > 0 && (g_i += 2))
			write(1, "0x", 2);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_base_low(num, 16);
	}
}

static	void	pf_print_o_id(unsigned long long int num, char wdc)
{
	if (g_s.ms)
	{
		if (!g_s.ll && !g_s.hh && g_s.hs && num && ++g_i)
			write(1, "0", 1);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || (g_s.zp && g_s.hs) || num)
			pf_putnbr_base_low(num, 8);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
	{
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		if (!g_s.ll && !g_s.hh && g_s.hs && num && ++g_i)
			write(1, "0", 1);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || (g_s.zp && g_s.hs) || num)
			pf_putnbr_base_low(num, 8);
	}
}

static	void	pf_print_u_id(unsigned long long int num, char wdc)
{
	if (g_s.ms)
	{
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_uns(num);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
	{
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_uns(num);
	}
}

void			pf_o_u_x_identifiers(va_list ap)
{
	ULLI			num;
	int				tmp;
	char			wdc;

	num = pf_get_value_uns(ap);
	tmp = pf_count_digits_base(num);
	wdc = (g_s.zr && !g_s.ms && !g_s.pr) ? '0' : ' ';
	g_s.hs = (g_s.id == 111 && g_s.pr > tmp) ? 0 : g_s.hs;
	g_s.wd -= (!g_s.ll && !g_s.hh && g_s.hs && g_s.id == 111) ? 1 : 0;
	if (!g_s.zp || num)
	{
		g_s.wd -= (tmp > g_s.pr) ? tmp : (g_s.pr);
		g_s.wd -= (!g_s.ll && !g_s.hh && g_s.hs && num && \
		(g_s.id == 88 || g_s.id == 120)) ? 2 : 0;
	}
	g_s.pr -= tmp;
	if (g_s.id == 88)
		pf_print_upperx_id(num, wdc);
	else if (g_s.id == 111)
		pf_print_o_id(num, wdc);
	else if (g_s.id == 117)
		pf_print_u_id(num, wdc);
	else if (g_s.id == 120)
		pf_print_lowerx_id(num, wdc);
}
