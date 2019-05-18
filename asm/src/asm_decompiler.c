/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_decompiler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:47:48 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:47:53 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	count_border(short mode)
{
	int		z;
	size_t	result;

	z = 0;
	if (mode == z)
		result = PROG_NAME_LENGTH + 4;
	else
		result = COMMENT_LENGTH + 4;
	return (result);
}

static void		read_and_write(struct s_lbs *l)
{
	char	x;
	size_t	len;
	char	*nl;

	nl = "\"\n";
	len = ft_strlen(nl);
	read(l->get, (char[4]){0}, 4);
	read(l->get, &x, 1);
	write(l->display, l->kind, ft_strlen(l->kind));
	while (l->ord_num < l->border && x)
	{
		write(l->display, &x, 1);
		read(l->get, &x, 1);
		l->ord_num++;
	}
	write(l->display, nl, len);
	while (l->ord_num++ < l->border)
		read(l->get, &x, 1);
}

short int		load_bwd_starting(long get, long display)
{
	struct s_lbs l;

	l.cmd_nm = ".name \"";
	l.cmd_cm = ".comment \"";
	l.k = 0;
	l.get = get;
	l.display = display;
	while (l.k <= 1)
	{
		l.ord_num = 1;
		if (l.k == 0)
		{
			l.kind = l.cmd_nm;
			l.border = count_border(0);
		}
		else
		{
			l.kind = l.cmd_cm;
			l.border = count_border(1);
		}
		read_and_write(&l);
		l.k++;
	}
	return (0);
}

short			load_bwd(long get, long display)
{
	char			e;
	int				i;
	unsigned char	num;
	int				f;
	size_t			code_set;

	f = display;
	i = 1;
	e = '\n';
	write(f, &e, i);
	f = read(get, &num, i);
	while (f >= i)
	{
		code_set = --num;
		if (code_set > 16)
			return (-1);
		else if (g_op_tab[code_set].octal)
			bwd_load_oct_handler(get, display, code_set);
		else
			bwd_load_else_handler(get, display, code_set);
		write(display, &e, i);
		f = read(get, &num, i);
	}
	return (1);
}

short			make_recoding(char *get_title, char *display_title)
{
	struct s_dcm d;

	if (get_title && display_title)
	{
		d.mode = 1;
		d.bz = -1;
		d.get = provide_source(get_title, d.mode);
		if (d.get <= d.bz)
		{
			show_details(RD_ERR);
			return (-3);
		}
		d.mode++;
		d.display = provide_source(display_title, d.mode);
		if (d.display <= d.bz)
			return (-1);
		load_bwd_starting(d.get, d.display);
		d.r = load_bwd(d.get, d.display);
		if (d.r <= d.bz)
		{
			show_details(DCM_ERR);
			return (-2);
		}
	}
	return (1);
}
