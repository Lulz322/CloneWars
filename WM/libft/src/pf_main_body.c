/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_main_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:27:24 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/12 20:27:25 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

static	void	pf_fill_functions_array(va_list ap)
{
	if (ap)
		return ;
	else
		return ;
}

static	void	pf_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	if (n != 0)
	{
		tmp = (unsigned char*)s;
		while (n-- != 0)
			*tmp++ = '\0';
	}
}

static	void	pf_fill_flags_structure(const char *s, va_list ap, int i)
{
	pf_bzero(&g_s, 56);
	while (!(DELIMA || DELIMB || DELIMC))
	{
		g_s.ms += ((i == 0 && s[i] == '-') || IS_MINUS) ? 1 : 0;
		g_s.ps += (s[i] == '+') ? 1 : 0;
		g_s.zr += (s[i] == '0' && !g_s.pr && !g_s.wd && !g_s.ms) ? 1 : 0;
		g_s.hs += (s[i] == '#') ? 1 : 0;
		g_s.sp += (s[i] == ' ' && i < 4) ? 1 : 0;
		g_s.wd += (IS_NUM && !g_s.dt && !g_s.wd) ? pf_atoi(&s[i]) : 0;
		g_s.tr += (TRASH) ? 1 : 0;
		g_s.dt += (s[i] == '.') ? 1 : 0;
		g_s.pr += (IS_NUM && g_s.dt && !g_s.pr) ? pf_atoi(&s[i]) : 0;
		g_s.ul += (s[i] == 'L') ? 1 : 0;
		g_s.hh += (s[i] == 'h') ? 1 : 0;
		g_s.ll += (s[i++] == 'l') ? 1 : 0;
	}
	g_s.id = ((int)s[i] == 100 || (int)s[i] == 105) ? 100 : (int)s[i];
	g_s.zp += (ZPA || ZPB || ZPC || ZPD || ZPE) ? 1 : 0;
	(g_s.tr) ? pf_print_trash(s) : g_fps[g_s.id](ap);
	if (s[i])
		pf_read_format(&s[++i], ap);
	else
		(g_s.tr) ? pf_read_format(&s[i], ap) : pf_read_format(s, ap);
}

void			pf_read_format(const char *str, va_list ap)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			pf_fill_flags_structure(&str[++i], ap, 0);
			return ;
		}
		else if (str[i] == '{')
		{
			pf_color_switch(&str[i], ap);
			return ;
		}
		else
		{
			write(1, &str[i], 1);
			g_i++;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	g_i = 0;
	i = 121;
	while (i--)
		g_fps[i] = &pf_fill_functions_array;
	g_fps[37] = &pf_mod_identifier;
	g_fps[100] = &pf_d_i_identifiers;
	g_fps[117] = &pf_o_u_x_identifiers;
	g_fps[111] = &pf_o_u_x_identifiers;
	g_fps[88] = &pf_o_u_x_identifiers;
	g_fps[120] = &pf_o_u_x_identifiers;
	g_fps[115] = &pf_s_identifier;
	g_fps[112] = &pf_p_identifier;
	g_fps[99] = &pf_c_identifier;
	g_fps[102] = &pf_f_identifier;
	va_start(ap, format);
	pf_read_format(format, ap);
	va_end(ap);
	return (g_i);
}
