/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonuses.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:41:44 by amatveie          #+#    #+#             */
/*   Updated: 2019/01/13 14:41:46 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_header.h"

void			pf_mod_identifier(va_list ap)
{
	char wdc;

	g_s.wd -= (ap) ? 1 : 1;
	wdc = (g_s.zr) ? '0' : ' ';
	if (g_s.ms)
	{
		write(1, "%", 1);
		++g_i;
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
	}
	else
	{
		while ((g_s.wd)-- > 0 && ++g_i)
			write(1, &wdc, 1);
		write(1, "%", 1);
		++g_i;
	}
}

static	int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}

void			pf_color_switch(const char *s, va_list ap)
{
	int i;

	i = 1;
	if (!ft_strncmp(s, "{black}", 7) && (i += 6))
		write(1, BLACK, 5);
	else if (!ft_strncmp(s, "{red}", 5) && (i += 4))
		write(1, RED, 5);
	else if (!ft_strncmp(s, "{yellow}", 8) && (i += 7))
		write(1, YELLOW, 5);
	else if (!ft_strncmp(s, "{green}", 7) && (i += 6))
		write(1, GREEN, 5);
	else if (!ft_strncmp(s, "{blue}", 6) && (i += 5))
		write(1, BLUE, 5);
	else if (!ft_strncmp(s, "{magenta}", 9) && (i += 8))
		write(1, MAGENTA, 5);
	else if (!ft_strncmp(s, "{cyan}", 6) && (i += 5))
		write(1, CYAN, 5);
	else if (!ft_strncmp(s, "{white}", 7) && (i += 6))
		write(1, WHITE, 5);
	else if (!ft_strncmp(s, "{eoc}", 5) && (i += 4))
		write(1, EOC, 4);
	else if (++g_i)
		write(1, "{", 1);
	pf_read_format((s + i), ap);
}

void			pf_print_trash(const char *s)
{
	int		i;
	char	wdc;

	wdc = (g_s.zr) ? '0' : ' ';
	i = 0;
	while (!TRASH || (s[i] >= '0' && s[i] <= '9') || s[i] == '-')
		i++;
	if (!g_s.ms)
		while ((g_s.wd)-- > 1 && ++g_i)
			write(1, &wdc, 1);
	write(1, &s[i], 1);
	g_i++;
	i++;
	if (s[i] && g_s.wd < 1 && ++g_i)
		write(1, &s[i++], 1);
	if (g_s.ms)
		while ((g_s.wd)-- > 1 && ++g_i)
			write(1, &wdc, 1);
	while (!(DELIMA || DELIMB || DELIMC) && s[i] && ++g_i)
		write(1, &s[i++], 1);
}
