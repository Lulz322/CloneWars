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

void	am_i_waiting(t_kareta *kareta)
{
	if (kareta->wait)
	{
		kareta->wait--;
		if (kareta->wait == 0)
			do_func(kareta);
	}
	else
		set_operation(kareta);
}

void	check_karetu(t_kareta *kareta)
{
	am_i_waiting(kareta);
	next_op(kareta);
}

void	run_cycle(void)
{
	t_kareta *tmp;

	PREPARE(tmp);
	while (tmp)
	{
		check_karetu(tmp);
		tmp->living++;
		tmp = tmp->next;
	}
}

void	start_game(void)
{
	while (ST.kareta)
	{
		LOG(ST.cycles + 1, ST.cycles_after_check + 1);
		if (RAVNO && (FD || FDUMP))
		{
			if (ST.flag_visual)
			{
				VS;
				timeout(-1);
				getch();
				endwin();
				exit(0);
			}
			else
				PRINT_B;
		}
		if (!FD && !FDUMP)
			VS;
		run_cycle();
		if (AM_I_DIE)
			check_who_die();
		logs(0, 0, 2);
	}
}

void	set_karetu(void)
{
	ST.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	CHECK_VISUALISATION;
	if (ST.flag_visual && ST.sounds)
		set_music();
	start_game();
}
