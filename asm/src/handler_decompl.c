/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_decompl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:56:17 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:56:20 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static short	ita_printed_freed(int num, long display)
{
	char *txt;

	txt = ft_itoa(num);
	ft_putstr_fd(txt, display);
	if (txt)
		free(txt);
	return (num);
}

void			bwd_comb_handler(struct s_disp d, size_t actnum,
								size_t upshot, int mode)
{
	char	x;

	x = 114;
	if (mode == DIR_CODE)
	{
		x = 37;
		if (g_op_tab[actnum].marker)
			upshot = get_into_1(d.get);
		else
			upshot = get_into_2(d.get);
		ft_putchar_fd(x, d.display);
	}
	else if (mode == IND_CODE)
		upshot = get_into_1(d.get);
	else if (mode == REG_CODE)
	{
		read(d.get, &upshot, 1);
		ft_putchar_fd(x, d.display);
	}
	ita_printed_freed(upshot, d.display);
}

void			bwd_load_oct_handler(long get, long display, size_t actnum)
{
	struct s_disp	d;
	unsigned char	objects;
	size_t			upshot;

	d.get = get;
	d.display = display;
	d.txt = ", ";
	d.s = 32;
	d.i = 0;
	read(d.get, &objects, 1);
	ft_putstr_fd(g_op_tab[actnum].name, d.display);
	ft_putchar_fd(d.s, d.display);
	while (d.i < g_op_tab[actnum].nb_arg)
	{
		upshot = (objects >> (6 - 2 * d.i)) & 0b11;
		if (upshot == DIR_CODE)
			bwd_comb_handler(d, actnum, upshot, DIR_CODE);
		if (upshot == IND_CODE)
			bwd_comb_handler(d, d.z, upshot, IND_CODE);
		if (upshot == REG_CODE)
			bwd_comb_handler(d, d.z, upshot, REG_CODE);
		if (d.i < g_op_tab[actnum].nb_arg - 1)
			ft_putstr_fd(d.txt, d.display);
		d.i++;
	}
}

void			bwd_load_else_handler(long get, long display, size_t actnum)
{
	size_t			upshot;
	struct s_disp	d;

	d.get = get;
	d.display = display;
	d.z = 0;
	d.s = ' ';
	d.i = d.z;
	d.txt = ", ";
	upshot = d.z;
	ft_putstr_fd(g_op_tab[actnum].name, d.display);
	ft_putchar_fd(d.s, d.display);
	while (d.i < g_op_tab[actnum].nb_arg)
	{
		if (g_op_tab[actnum].args[d.i] == DIR_CODE)
			bwd_comb_handler(d, actnum, upshot, DIR_CODE);
		if (g_op_tab[actnum].args[d.i] == REG_CODE)
			bwd_comb_handler(d, d.z, upshot, 3);
		if (g_op_tab[actnum].args[d.i] == IND_CODE)
			bwd_comb_handler(d, d.z, upshot, IND_CODE);
		if (d.i < g_op_tab[actnum].nb_arg - REG_CODE)
			ft_putstr_fd(d.txt, d.display);
		d.i++;
	}
}
