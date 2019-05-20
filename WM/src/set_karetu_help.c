/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_karetu_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 15:32:49 by iruban            #+#    #+#             */
/*   Updated: 2019/05/18 15:32:50 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		set_wait_time(t_kareta *kareta)
{
	if (!kareta->wait)
	{
		kareta->code = g_gen.field[kareta->pos];
		if (POOP)
			kareta->wait = g_op[kareta->code - 1].cycles;
	}
	if (kareta->wait > 0)
		kareta->wait--;
}

t_operation	*set_func(t_kareta *kareta)
{
	if (kareta->code >= 0x01 && kareta->code <= 0x10)
		return (&g_op[kareta->code - 1]);
	else
		return (NULL);
}

t_kareta	*u_are_not_prepeare(void)
{
	t_kareta *start;

	g_gen.cycles++;
	g_gen.cycles_after_check++;
	start = g_gen.kareta;
	if (g_gen.cycles % 1000 == 1)
		set_music();
	return (start);
}

void		help_vs(int mod)
{
	if (mod == 1)
	{
		if (!FD && !FDUMP)
		{
			if (g_gen.flag_visual)
			{
				vs_update_stats(&g_gen.v);
				vs_update_main(&g_gen.v);
			}
		}
	}
	else
	{
		vs_update_main(&g_gen.v);
		vs_update_stats(&g_gen.v);
		vs_update_stats(&g_gen.v);
		vs_update_main(&g_gen.v);
	}
}
