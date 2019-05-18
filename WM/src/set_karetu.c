/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_karetu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:49:29 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 12:49:30 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void set_wait_time(t_kareta *kareta)
{
	if (!kareta->wait)
		set_operation(kareta);
	if (kareta->wait > 0)
		kareta->wait--;
}


t_operation *set_func(t_kareta *kareta)
{
	if (kareta->code >= 0x01 && kareta->code <= 0x10)
		return(&g_op[kareta->code - 1]);
	else
		return (NULL);
}

void	check_kareta(t_kareta *kareta)
{
	t_operation	*new;

	set_wait_time(kareta);
	if (!kareta->wait)
	{
		if ((new = set_func(kareta)))
		{
			r_arg(kareta, new);
			if (val_argc(kareta, new) && check_args(kareta, new))
				new->func(kareta);
			else
				kareta->step += g_farewell(kareta, new);
		}
		else
			kareta->step++;
	}
}

t_kareta *u_are_not_prepeare()
{
	t_kareta *start;

	g_gen.cycles++;
	g_gen.cycles_after_check++;
	start = g_gen.kareta;
	if (g_gen.cycles % 1000 == 1)
		set_music();
	return (start);
}

void	run_cycle()
{
	t_kareta *tmp;

	if (g_gen.log == 2)
		logs(g_gen.cycles + 1, g_gen.cycles_after_check + 1, 1);
	tmp = u_are_not_prepeare();
	while (tmp)
	{
		check_kareta(tmp);
		next_op(tmp);
		tmp = tmp->next;
	}
}

void	help_vs(void)
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

void	start_game(void)
{
	while (g_gen.kareta)
	{
		if (RAVNO && (FD || FDUMP))
		{
			if (g_gen.flag_visual)
			{
				help_vs();
				timeout(-1);
				getch();
				endwin();
				exit(0);
			}
			else
				gavno();
		}
		help_vs();
		run_cycle();
		if (AM_I_DIE)
			check_who_die();
		logs(0, 0, 2);
	}
}

void	set_karetu(void)
{
	g_gen.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	if (g_gen.flag_visual == true)
	{
		vs_main();
		help_vs();
	}
	if (g_gen.flag_visual && g_gen.sounds)
		set_music();
	start_game();
}
