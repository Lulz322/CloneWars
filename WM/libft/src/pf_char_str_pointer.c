/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char_str_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:26:30 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:26:33 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

void			pf_c_identifier(va_list ap)
{
	unsigned char	c;
	char			wdc;

	c = (unsigned char)va_arg(ap, int);
	g_s.wd -= 1;
	wdc = (g_s.zr) ? '0' : ' ';
	if (g_s.ms && ++g_i)
	{
		write(1, &c, 1);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
	}
	else
	{
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		write(1, &c, 1);
		g_i++;
	}
}

static	void	pf_print_p_id(char *p, char wdc)
{
	if (g_s.zr && (g_i += 2))
		write(1, "0x", 2);
	while ((g_s.wd)-- > 0 && ++g_i)
		write(1, &wdc, 1);
	if (!g_s.zr && (g_i += 2))
		write(1, "0x", 2);
	while (!g_s.zp && (g_s.pr)-- > 0 && ++g_i)
		write(1, "0", 1);
	if (!g_s.zp || p)
		pf_putnbr_base_low((long)p, 16);
}

void			pf_p_identifier(va_list ap)
{
	char	*p;
	int		tmp;
	char	wdc;

	p = va_arg(ap, void *);
	tmp = pf_count_digits_base((long)p);
	g_s.pr -= tmp;
	if (!g_s.zp || p)
		g_s.wd -= tmp;
	g_s.wd -= (g_s.pr > 0) ? (g_s.pr + 2) : 2;
	wdc = (g_s.zr) ? '0' : ' ';
	if (g_s.ms)
	{
		write(1, "0x", 2);
		g_i += 2;
		while (!g_s.zp && (g_s.pr)-- > 0 && ++g_i)
			write(1, "0", 1);
		if (!g_s.zp || p)
			pf_putnbr_base_low((long)p, 16);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, " ", 1);
	}
	else
		pf_print_p_id(p, wdc);
}

static	void	pf_print_s_id(const char *s, char wdc)
{
	if (g_s.ms)
	{
		if (g_s.dt)
			pf_putnstr(s, g_s.pr);
		else
			pf_putstr(s);
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
	}
	else
	{
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		if (g_s.dt)
			pf_putnstr(s, g_s.pr);
		else
			pf_putstr(s);
	}
}

void			pf_s_identifier(va_list ap)
{
	const char	*s = "(null)";
	const char	*pass;
	int			tmp;
	char		wdc;

	pass = va_arg(ap, const char *);
	s = (pass != NULL) ? pass : s;
	s = (g_s.zp) ? NULL : s;
	wdc = (g_s.zr) ? '0' : ' ';
	tmp = (g_s.zp) ? 0 : pf_strlen(s);
	g_s.pr = (g_s.pr > tmp || g_s.pr < 0) ? tmp : g_s.pr;
	g_s.wd -= (g_s.pr > 0) ? g_s.pr : tmp;
	pf_print_s_id(s, wdc);
}
