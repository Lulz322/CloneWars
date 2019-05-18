/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:15:27 by amatveie          #+#    #+#             */
/*   Updated: 2019/05/17 12:15:28 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		vs_init_color(void)
{
	init_color(COLOR_MAGENTA, 300, 300, 300);
	init_color(COLOR_WHITE, 900, 900, 900);
	init_color(COLOR_RED, 1000, 0, 0);
	init_color(COLOR_YELLOW, 1000, 700, 0);
	init_color(COLOR_CYAN, 150, 500, 950);
	init_color(COLOR_GREEN, 200, 950, 200);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(12, COLOR_BLACK, COLOR_YELLOW);
	init_pair(13, COLOR_BLACK, COLOR_CYAN);
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	init_pair(15, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(21, COLOR_WHITE, COLOR_RED);
	init_pair(22, COLOR_WHITE, COLOR_YELLOW);
	init_pair(23, COLOR_WHITE, COLOR_CYAN);
	init_pair(24, COLOR_WHITE, COLOR_GREEN);
	init_pair(25, COLOR_WHITE, COLOR_MAGENTA);
}

static int	vs_init_screen(t_vis *v)
{
	initscr();
	timeout(0);
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	vs_init_color();
	getmaxyx(stdscr, v->y, v->x);
	if (v->x < 262 || v->y < 70)
	{
		endwin();
		if (g_gen.f_p)
			write(1, "Термінал замалий для візуалізації\n", 34);
		else
			write(1, "Term size is too small for the visualization\n", 45);
		return (0);
	}
	v->main = newwin(66, 195, 2, 2);
	v->stat = newwin(66, 60, 2, 198);
	return (1);
}

void		vs_prepare_stat(t_vis *v)
{
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 1, 20, ((g_gen.f_p) ? UA1 : EN1));
	wattroff(v->stat, COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 3, 2, ((g_gen.f_p) ? UA2 : EN2));
	wattroff(v->stat, A_BOLD);
	wattron(v->stat, A_UNDERLINE | COLOR_PAIR(GREEN_BLACK));
	mvwprintw(v->stat, 3, 20, ((g_gen.f_p) ? "біжиить" : "running"));
	wattroff(v->stat, A_UNDERLINE | COLOR_PAIR(GREEN_BLACK));
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 5, 2, ((g_gen.f_p) ? "Цикл:" : "Cycle:"));
	mvwprintw(v->stat, 7, 2, ((g_gen.f_p) ? "Процеси:" : "Processes:"));
	mvwprintw(v->stat, 9, 2, ((g_gen.f_p) ? UA3 : EN3));
	mvwprintw(v->stat, 36, 2, ((g_gen.f_p) ? UA4 : EN4), CYCLE_TO_DIE);
	mvwprintw(v->stat, 42, 2, ((g_gen.f_p) ? UA5 : EN5));
	mvwprintw(v->stat, 43, 2, ((g_gen.f_p) ? "КЛК_ЖИВІ: " : "NBR_LIVE: "));
	mvwprintw(v->stat, 44, 2, ((g_gen.f_p) ? "МАХ_ПЕР-ОК: " : "MAX_CHECKS: "));
	wattroff(v->stat, A_BOLD);
	mvwprintw(v->stat, 42, 15, "%d", CYCLE_DELTA);
	mvwprintw(v->stat, 43, 15, "%d", NBR_LIVE);
	mvwprintw(v->stat, 44, 15, "%d", MAX_CHECKS);
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 2, ((g_gen.f_p) ? "Створений:" : "Created by:"));
	wattroff(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 14, "iruban, mbiliaie, dlenskyi, amatveie");
	wrefresh(v->stat);
}

static void	vs_prepare_main(t_vis *v)
{
	int y;
	int x;

	y = 1;
	wattron(v->main, COLOR_PAIR(GRAY_BLACK));
	while (y < 65)
	{
		x = -1;
		while ((x += 3) < 194)
			mvwprintw(v->main, y, x, "%02x", 1);
		y++;
	}
	wattroff(v->main, COLOR_PAIR(1));
	wrefresh(v->main);
}

void		vs_main(void)
{
	t_vis v;

	ft_bzero(&v, 8);
	if (vs_init_screen(&v))
	{
		vs_prepare_main(&v);
		vs_prepare_stat(&v);
		vs_print_players(&v);
		g_gen.v = v;
	}
	else
	{
		g_gen.flag_visual = false;
	}
}
