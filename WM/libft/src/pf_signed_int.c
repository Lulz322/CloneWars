/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_signed_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:27:32 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:34 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

static	void	pf_print_sgn_id(long long int num, char wdc, char sgn)
{
	if (g_s.ms)
	{
		if (sgn && ++g_i)
			write(1, &sgn, 1);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_sgn(num);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
	{
		if (g_s.zr && sgn && ++g_i)
			write(1, &sgn, 1);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		if (!g_s.zr && sgn && ++g_i)
			write(1, &sgn, 1);
		while ((g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || num)
			pf_putnbr_sgn(num);
	}
}

void			pf_d_i_identifiers(va_list ap)
{
	LLI		num;
	int		tmp;
	char	wdc;
	char	sgn;

	sgn = '\0';
	num = pf_get_value_sgn(ap);
	tmp = pf_count_digits_sgn(num);
	wdc = (g_s.zr && !g_s.ms && !g_s.pr) ? '0' : ' ';
	if (g_s.ps && num >= 0)
		sgn = '+';
	else if (g_s.sp && num >= 0)
		sgn = ' ';
	else if (num < 0)
		sgn = '-';
	if (!g_s.zp || num)
	{
		g_s.wd -= (tmp > g_s.pr) ? tmp : (g_s.pr);
		g_s.wd -= (sgn) ? 1 : 0;
		g_s.pr -= tmp;
	}
	pf_print_sgn_id(num, wdc, sgn);
}
