/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_announce_winner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatveie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 12:14:50 by amatveie          #+#    #+#             */
/*   Updated: 2019/05/17 12:14:52 by amatveie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	vs_chicken_dinner(int y, int x)
{
	mvprintw(y / 3 + 12, x / 3, C1);
	mvprintw(y / 3 + 13, x / 3, C2);
	mvprintw(y / 3 + 14, x / 3, C3);
	mvprintw(y / 3 + 15, x / 3, Y);
	mvprintw(y / 3 + 16, x / 3, C5);
	mvprintw(y / 3 + 17, x / 3, C6);
	mvprintw(y / 3 + 18, x / 3, L);
	mvprintw(y / 3 + 19, x / 3, C8);
	mvprintw(y / 3 + 20, x / 3, C9);
	mvprintw(y / 3 + 12, x / 3 + 69, D1);
	mvprintw(y / 3 + 13, x / 3 + 69, D2);
	mvprintw(y / 3 + 14, x / 3 + 69, D3);
	mvprintw(y / 3 + 15, x / 3 + 69, D4);
	mvprintw(y / 3 + 16, x / 3 + 69, D5);
	mvprintw(y / 3 + 17, x / 3 + 69, D6);
	mvprintw(y / 3 + 18, x / 3 + 69, D7);
	mvprintw(y / 3 + 19, x / 3 + 69, D8);
	mvprintw(y / 3 + 20, x / 3 + 69, D9);
}

static void	vs_winner_winner(int y, int x)
{
	attron(A_BLINK | A_BOLD);
	mvprintw(y / 3, x / 3, WIN1);
	mvprintw(y / 3 + 1, x / 3, WIN2);
	mvprintw(y / 3 + 2, x / 3, WIN3);
	mvprintw(y / 3 + 3, x / 3, WIN4);
	mvprintw(y / 3 + 4, x / 3, WIN5);
	mvprintw(y / 3 + 5, x / 3, WIN6);
	mvprintw(y / 3 + 6, x / 3, WIN7);
	mvprintw(y / 3 + 7, x / 3, WIN8);
	mvprintw(y / 3 + 8, x / 3, WIN9);
	mvprintw(y / 3, x / 3 + 71, WIN1);
	mvprintw(y / 3 + 1, x / 3 + 71, WIN2);
	mvprintw(y / 3 + 2, x / 3 + 71, WIN3);
	mvprintw(y / 3 + 3, x / 3 + 71, WIN4);
	mvprintw(y / 3 + 4, x / 3 + 71, WIN5);
	mvprintw(y / 3 + 5, x / 3 + 71, WIN6);
	mvprintw(y / 3 + 6, x / 3 + 71, WIN7);
	mvprintw(y / 3 + 7, x / 3 + 71, WIN8);
	mvprintw(y / 3 + 8, x / 3 + 71, WIN9);
	vs_chicken_dinner(y, x);
}

static void	vs_peremoga(int y, int x)
{
	attron(A_BLINK | A_BOLD);
	mvprintw(y / 3, x / 3, Z);
	mvprintw(y / 3 + 1, x / 3, O);
	mvprintw(y / 3 + 2, x / 3, P);
	mvprintw(y / 3 + 3, x / 3, X);
	mvprintw(y / 3 + 4, x / 3, B);
	mvprintw(y / 3 + 5, x / 3, K);
	mvprintw(y / 3 + 6, x / 3, J);
}

static void	vs_prepare_winer(int *y, int *x, int *len)
{
	endwin();
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	vs_init_color();
	getmaxyx(stdscr, *y, *x);
	timeout(-1);
	box(stdscr, 0, 0);
	*len = ft_strlen(g_gen.champ[g_gen.last_alive].name);
	refresh();
}

void		vs_announce_winner(int i, int j, int o)
{
	int y;
	int x;
	int len;

	i = 1;
	vs_prepare_winer(&y, &x, &len);
	attron(COLOR_PAIR(g_gen.last_alive + 1));
	while (i < y - 1)
	{
		j = 2;
		while (j < x - 1)
		{
			if (o - 1 == len)
				o = 0;
			mvprintw(i, j, "%c", g_gen.champ[g_gen.last_alive].name[o]);
			j += 2;
			o++;
		}
		i++;
	}
	attroff(COLOR_PAIR(g_gen.last_alive + 1));
	(g_gen.f_p) ? vs_peremoga(y + 35, x + 67) : vs_winner_winner(y, x);
	refresh();
	getch();
	endwin();
}
