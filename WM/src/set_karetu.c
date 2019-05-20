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

void	check_kareta(t_kareta *kareta)
{
	t_operation	*new;

	set_wait_time(kareta);
	if (kareta->wait == 0)
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

void	run_cycle(void)
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

void	start_game(void)
{
	while (g_gen.kareta)
	{
		if (RAVNO && (FD || FDUMP))
		{
			if (g_gen.flag_visual)
			{
				help_vs(2);
				timeout(-1);
				getch();
				endwin();
				exit(0);
			}
			else
				print_field();
		}
		help_vs(1);
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
		help_vs(2);
	}
	if (g_gen.flag_visual && g_gen.sounds)
		set_music();
	start_game();
}
