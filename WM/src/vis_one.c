#include "../includes/vm.h"

typedef struct	s_vis
{
	int			y;
	int			x;
	WINDOW		*main;
	WINDOW		*stat;
}				t_vis;

#define GRAY_BLACK 1
#define WHITE_BLACK 2
#define RED_BLACK 3
#define YELLOW_BLACK 4
#define BLUE_BLACK 5
#define GREEN_BLACK 6
#define BLACK_RED 7
#define BLACK_YELLOW 8
#define BLACK_BLUE 9
#define BLACK_GREEN 10
#define WHITE_GREEN 11
#define WHITE_RED 12
#define WHITE_YELLOW 13
#define WHITE_BLUE 14

void	vs_init_color(void)
{
	init_color(COLOR_MAGENTA, 475, 475, 475);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_RED, 1000, 0, 0);
	init_color(COLOR_YELLOW, 1000, 700, 0);
	init_color(COLOR_CYAN, 0, 1000, 1000);
	init_color(COLOR_GREEN, 0, 350, 0);
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);//gray
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(10, COLOR_BLACK, COLOR_GREEN);
	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_RED);
	init_pair(13, COLOR_WHITE, COLOR_YELLOW);
	init_pair(14, COLOR_WHITE, COLOR_CYAN);
}

void	vs_init_screen(t_vis *v)
{
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	vs_init_color();
	getmaxyx(stdscr, v->y, v->x);
	if (v->x < 262 || v->y < 70)
	{
		endwin();
		write(1, "Term size is too small for the visualization\n", 45);
		return ;
	}
	v->main = newwin(66, 195, 2, 2);
	v->stat = newwin(66, 60, 2, 198);
	box(v->main, 0, 0);
	box(v->stat, 0, 0);
}

void	vs_prepare_main(t_vis *v)
{
	int y;
	int x;

	y = 1;
	wattron(v->main, COLOR_PAIR(1));
	while (y < 65)
	{
		x = -1;
		while ((x += 3) < 194)
			mvwprintw(v->main, y, x, "%02d", 1);
		y++;
	}
	wattroff(v->main, COLOR_PAIR(1));
	wrefresh(v->main);
}

void	vs_print_players(t_vis *v)
{
	int i;
	int y;

	i = 1;
	y = 12;	
	while (i <= g_gen.am_champs)
	{
		mvwprintw(v->stat, y, 2, "Player %d: ", i);
		wattron(v->stat, COLOR_PAIR(i + 2) | A_BOLD);
		mvwprintw(v->stat, y, 12, "%.30s", g_gen.champ->name);
		mvwprintw(v->stat, y + 3, 2, "%.50s", g_gen.champ->comment);
		wattroff(v->stat, COLOR_PAIR(i + 2) | A_BOLD);
		mvwprintw(v->stat, y + 1, 6, "Last cycle alive: n/a");
		mvwprintw(v->stat, y + 2, 6, "Cycles reported alive: n/a");
		i++;
		y += 5;
	}
	wrefresh(v->stat);
}

void	vs_update_players(t_vis *v)
{
	int i;
	int y;

	i = 1;
	y = 12;	
	while (i <= g_gen.am_champs)
	{
		mvwprintw(v->stat, y + 1, 30, "%d", g_gen.champ->last_alive);
		mvwprintw(v->stat, y + 2, 30, "%d", g_gen.champ->live);
		i++;
		y += 5;
	}
}

void	vs_update_stats(t_vis *v)
{
	int len;
	int x;
	int i;

	i = 0;
	x = 3;
	len = (CYCLE_TO_DIE / 54) / (g_gen.cycles_to_die / 54);
	//add check if game is paused
	mvwprintw(v->stat, 5, 9, "%d", g_gen.cycles);
	mvwprintw(v->stat, 7, 13, "%d", g_gen.cycles_after_check);
	mvwprintw(v->stat, 9, 17, "%d", g_gen.am_karet);
	mvwprintw(v->stat, 36, 17, "%d", g_gen.cycles_to_die);
	while (i < len)
	{
		mvwprintw(v->stat, 38, x, "#");
		i++;
		x++;
	}
	vs_update_players(v);
	wrefresh(v->stat);
}

void	vs_prepare_stat(t_vis *v)
{
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 1, 20, "*** STATISTICS ***");
	wattroff(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 3, 2, "Execution status: running...");
	mvwprintw(v->stat, 5, 2, "Cycle:");
	mvwprintw(v->stat, 7, 2, "Processes:");
	mvwprintw(v->stat, 9, 2, "Carries alive:");
	mvwprintw(v->stat, 36, 2, "Cycles to die:               / %d", CYCLE_TO_DIE);
	mvwprintw(v->stat, 38, 2, "[------------------------------------------------------]");
	mvwprintw(v->stat, 44, 2, "CYCLE_DELTA: %d", CYCLE_DELTA);
	mvwprintw(v->stat, 46, 2, "NBR_LIVE: %d", NBR_LIVE);
	mvwprintw(v->stat, 48, 2, "MAX_CHECKS: %d", MAX_CHECKS);
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 2, "Created by:");
	wattroff(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 14, "iruban, mbiliaie, dlenskyi, amatveie");
	wrefresh(v->stat);
}

void	vs_main(void)
{
	t_vis v;
	int c = 'a';

	ft_bzero(&v, 8);
	vs_init_screen(&v);
	vs_prepare_main(&v);
	vs_prepare_stat(&v);
	vs_print_players(&v);

	while (c != 'q')
	{
		c = wgetch(v.main);
	}

	endwin();
}
/*
int main()
{
	vs_main();
	return (1);
}
*/
