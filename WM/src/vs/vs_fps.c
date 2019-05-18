/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:15:11 by amatveie          #+#    #+#             */
/*   Updated: 2019/05/17 12:15:12 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		vs_print_players(t_vis *v)
{
	int i;
	int y;

	i = 1;
	y = 12;
	while (i <= g_gen.am_champs)
	{
		wattron(v->stat, A_BOLD);
		mvwprintw(v->stat, y, 2, ((g_gen.f_p) ? UA6 : EN6), i);
		wattroff(v->stat, A_BOLD);
		wattron(v->stat, COLOR_PAIR(i));
		mvwprintw(v->stat, y, 13, "%.30s", g_gen.champ[i - 1].name);
		mvwprintw(v->stat, y + 3, 6, "%.50s", g_gen.champ[i - 1].comment);
		wattroff(v->stat, COLOR_PAIR(i));
		mvwprintw(v->stat, y + 1, 6, ((g_gen.f_p) ? UA7 : EN7));
		mvwprintw(v->stat, y + 2, 6, ((g_gen.f_p) ? UA8 : EN8));
		i++;
		y += 6;
	}
	wrefresh(v->stat);
}

static void	vs_update_players(t_vis *v)
{
	int i;
	int y;

	i = -1;
	y = 12;
	vs_print_players(v);
	while (++i <= g_gen.am_champs - 1)
	{
		mvwprintw(v->stat, y + 1, 30, "%d           ", \
		g_gen.champ[i].last_alive);
		mvwprintw(v->stat, y + 2, 30, "%d           ", g_gen.champ[i].live);
		y += 6;
	}
}

static void	vs_print_kolbaska(t_vis *v)
{
	float	len;
	int		x;
	int		i;

	i = 0;
	x = 3;
	len = (float)(CYCLE_TO_DIE / 27) - (float)(g_gen.cycles_to_die / 27);
	mvwprintw(v->stat, 38, 2, KOLBASKA);
	while (i < (int)len && i < 54)
	{
		mvwprintw(v->stat, 38, x, ((g_gen.f_p) ? TRD : "#"));
		i += (g_gen.f_p) ? 2 : 1;
		x += (g_gen.f_p) ? 2 : 1;
	}
}

void		vs_update_stats(t_vis *v)
{
	vs_prepare_stat(v);
	vs_check_key_events(v);
	mvwprintw(v->stat, 5, 20, "%d      ", g_gen.cycles);
	mvwprintw(v->stat, 7, 20, "%d      ", g_gen.cycles_after_check);
	mvwprintw(v->stat, 9, 20, "%d      ", g_gen.am_karet);
	wattron(v->stat, A_BOLD);
	vs_print_kolbaska(v);
	vs_print_42(v, 110);
	wattroff(v->stat, A_BOLD);
	vs_update_players(v);
	wrefresh(v->stat);
}

void		vs_update_main(t_vis *v)
{
	t_print st;

	st.i = 0;
	st.y = 1;
	box(v->main, 0, 0);
	box(v->stat, 0, 0);
	while (st.y < 65 && st.i < 4096)
	{
		st.x = -1;
		while ((st.x += 3) < 194 && st.i < 4096)
		{
			if ((st.k = karettta(st.i)))
				st.color = st.k + 10;
			else
				st.color = g_gen.v_field[st.i];
			st.color += (st.k && is_dat_is_a_child(st.i) == true) ? 10 : 0;
			st.color = (st.color) ? st.color : 5;
			wattron(v->main, COLOR_PAIR(st.color));
			mvwprintw(v->main, st.y, st.x, "%02x", g_gen.field[st.i]);
			wattroff(v->main, COLOR_PAIR(st.color));
			st.i++;
		}
		st.y++;
	}
	wrefresh(v->main);
}
