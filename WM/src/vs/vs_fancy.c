/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_fancy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:15:00 by amatveie          #+#    #+#             */
/*   Updated: 2019/05/17 12:15:02 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	vs_corewar(WINDOW *win)
{
	mvwprintw(win, 46, 2, " _______  _______  ______    _______ ");
	mvwprintw(win, 47, 2, "|       ||       ||    _ |  |       |");
	mvwprintw(win, 48, 2, "|       ||   _   ||   | ||  |    ___|");
	mvwprintw(win, 49, 2, "|       ||  | |  ||   |_||_ |   |___ ");
	mvwprintw(win, 50, 2, "|      _||  |_|  ||    __  ||    ___|");
	mvwprintw(win, 51, 2, "|     |_ |       ||   |  | ||   |___ ");
	mvwprintw(win, 52, 2, "|_______||_______||___|  |_||_______|");
	mvwprintw(win, 53, 4, " _     _  _______  ______ ");
	mvwprintw(win, 54, 4, "| | _ | ||   _   ||    _ |");
	mvwprintw(win, 55, 4, "| || || ||  |_|  ||   | ||");
	mvwprintw(win, 56, 4, "|       ||       ||   |_||_ ");
	mvwprintw(win, 57, 4, "|       ||       ||    __  |");
	mvwprintw(win, 58, 4, "|   _   ||   _   ||   |  | |");
	mvwprintw(win, 59, 4, "|__| |__||__| |__||___|  |_|");
}

static void	vs_42_one(t_vis *v)
{
	wattron(v->stat, COLOR_PAIR(1));
	vs_corewar(v->stat);
	mvwprintw(v->stat, 53, 35, " __    __     ______    ");
	mvwprintw(v->stat, 54, 35, "/  |  /  |   /      \\  ");
	mvwprintw(v->stat, 55, 35, "$$ |  $$ |  /$$$$$$  |  ");
	mvwprintw(v->stat, 56, 35, "$$ |__$$ |  $$____$$ |  ");
	mvwprintw(v->stat, 57, 35, "$$    $$ |   /    $$/   ");
	mvwprintw(v->stat, 58, 35, "$$$$$$$$ |  /$$$$$$/    ");
	mvwprintw(v->stat, 59, 35, "      $$ |  $$ |_____   ");
	mvwprintw(v->stat, 60, 35, "      $$ |  $$       |  ");
	mvwprintw(v->stat, 61, 35, "      $$/   $$$$$$$$/   ");
	wattroff(v->stat, COLOR_PAIR(1));
}

static void	vs_42_two(t_vis *v)
{
	wattron(v->stat, COLOR_PAIR(2));
	vs_corewar(v->stat);
	mvwprintw(v->stat, 53, 35, "                        ");
	mvwprintw(v->stat, 54, 35, " /$$   /$$    /$$$$$$   ");
	mvwprintw(v->stat, 55, 35, "| $$  | $$   /$$__  $$  ");
	mvwprintw(v->stat, 56, 35, "| $$  | $$  |__/  \\ $$ ");
	mvwprintw(v->stat, 57, 35, "| $$$$$$$$    /$$$$$$/  ");
	mvwprintw(v->stat, 58, 35, "|_____  $$   /$$____/   ");
	mvwprintw(v->stat, 59, 35, "      | $$  | $$        ");
	mvwprintw(v->stat, 60, 35, "      | $$  | $$$$$$$$  ");
	mvwprintw(v->stat, 61, 35, "      |__/  |________/  ");
	wattroff(v->stat, COLOR_PAIR(2));
}

static void	vs_gerb(t_vis *v, int color)
{
	wattron(v->stat, COLOR_PAIR(color));
	mvwprintw(v->stat, 40, 37, G3);
	mvwprintw(v->stat, 41, 18, G4);
	mvwprintw(v->stat, 42, 18, G5);
	mvwprintw(v->stat, 43, 18, G6);
	mvwprintw(v->stat, 44, 18, G7);
	mvwprintw(v->stat, 45, 18, G8);
	mvwprintw(v->stat, 46, 18, G9);
	mvwprintw(v->stat, 47, 18, G10);
	mvwprintw(v->stat, 48, 18, G11);
	mvwprintw(v->stat, 49, 18, G12);
	mvwprintw(v->stat, 50, 18, G13);
	mvwprintw(v->stat, 51, 18, G14);
	mvwprintw(v->stat, 52, 18, G15);
	mvwprintw(v->stat, 53, 18, G16);
	mvwprintw(v->stat, 54, 18, G17);
	mvwprintw(v->stat, 55, 18, G18);
	mvwprintw(v->stat, 56, 18, G19);
	mvwprintw(v->stat, 57, 18, G20);
	mvwprintw(v->stat, 58, 18, G21);
	mvwprintw(v->stat, 59, 18, G22);
	mvwprintw(v->stat, 60, 18, G23);
	mvwprintw(v->stat, 61, 18, G24);
	mvwprintw(v->stat, 62, 18, G25);
	wattroff(v->stat, COLOR_PAIR(color));
}

void		vs_print_42(t_vis *v, int mod)
{
	static int i;

	if (g_gen.cycles > 15000)
		mod = 1;
	else if (g_gen.cycles > 13500)
		mod = 2;
	else if (g_gen.cycles > 12000)
		mod = 5;
	else if (g_gen.cycles > 10000)
		mod = 10;
	else if (g_gen.cycles > 7000)
		mod = 30;
	else if (g_gen.cycles > 5000)
		mod = 50;
	if (!(g_gen.cycles % mod))
	{
		if (g_gen.f_p)
			(i == 1) ? vs_gerb(v, BLUE_BLACK) : vs_gerb(v, YELLOW_BLACK);
		else
			(i == 1) ? vs_42_one(v) : vs_42_two(v);
		i++;
		i = (i > 2) ? 1 : i;
	}
}
