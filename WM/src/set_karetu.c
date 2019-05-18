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
	return (start);
}

void	run_cycle()
{
	t_kareta *tmp;

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
		LOG(g_gen.cycles + 1, g_gen.cycles_after_check + 1);
		if (RAVNO && (FD || FDUMP))
		{
			if (g_gen.flag_visual)
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
	g_gen.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	CHECK_VISUALISATION;
	set_ukr_names();
	ft_printf("%s\n", g_gen.champ[0].UKR_name);
	if (g_gen.flag_visual && g_gen.sounds)
		set_music();
	start_game();
}
