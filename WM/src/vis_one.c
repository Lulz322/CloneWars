#include "../includes/vm.h"

#define RED_BLACK 1
#define YELLOW_BLACK 2
#define BLUE_BLACK 3
#define GREEN_BLACK 4
#define GRAY_BLACK 5
#define WHITE_BLACK 6
#define BLACK_RED 11
#define BLACK_YELLOW 12
#define BLACK_BLUE 13
#define BLACK_GREEN 14
#define BLACK_GREY 15
#define WHITE_RED 21
#define WHITE_YELLOW 22
#define WHITE_BLUE 23
#define WHITE_GREEN 24
#define WHITE_GREY 25

#define KOLBASKA "[------------------------------------------------------]"

// void	vs_print_42(int i)
// {

// }


void	vs_init_color(void)
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
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);//gray
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

void	vs_print_players(t_vis *v)
{
	int i;
	int y;

	i = 1;
	y = 12;
	while (i <= g_gen.am_champs)
	{
		wattron(v->stat, A_BOLD);
		mvwprintw(v->stat, y, 2, "Player %d: ", i);
		wattroff(v->stat, A_BOLD);
		wattron(v->stat, COLOR_PAIR(i));
		mvwprintw(v->stat, y, 12, "%.30s", g_gen.champ[i - 1].name);
		mvwprintw(v->stat, y + 3, 6, "%.50s", g_gen.champ[i -1].comment);
		wattroff(v->stat, COLOR_PAIR(i));
		mvwprintw(v->stat, y + 1, 6, "Last cycle alive: ");
		mvwprintw(v->stat, y + 2, 6, "Cycles reported alive: ");
		i++;
		y += 6;
	}
	wrefresh(v->stat);
}

void	vs_update_players(t_vis *v)
{
	int i;
	int y;

	i = -1;
	y = 12;
	while (++i <= g_gen.am_champs - 1)
	{
		mvwprintw(v->stat, y + 1, 30, "%d           ", g_gen.champ[i].last_alive);
		mvwprintw(v->stat, y + 2, 30, "%d           ", g_gen.champ[i].live);
		y += 6;
	}
}

void	vs_update_stats(t_vis *v)
{
	float len;
	int x;
	int i;

	i = 0;
	x = 3;
	len = (float)(CYCLE_TO_DIE / 27)- (float)(g_gen.cycles_to_die / 27);
	//add check if game is paused
	mvwprintw(v->stat, 5, 9, "%d      ", g_gen.cycles);
	mvwprintw(v->stat, 7, 13, "%d      ", g_gen.cycles_after_check);
	mvwprintw(v->stat, 9, 17, "%d      ", g_gen.am_karet);
	mvwprintw(v->stat, 36, 17, "    ");
	mvwprintw(v->stat, 36, 17, "%d", g_gen.cycles_to_die);
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 38, 2, KOLBASKA);
	while (i < (int)len && i < 54)
	{
		mvwprintw(v->stat, 38, x, "#");
		i++;
		x++;
	}
	wattroff(v->stat, A_BOLD);
	vs_update_players(v);
	wrefresh(v->stat);
	
}

void	vs_update_main(t_vis *v)
{
	int y;
	int x;
	int i;
	int color;
	int k;

	i = 0;
	y = 1;
	while (y < 65 && i < 4096)
	{
		x = -1;
		while ((x += 3) < 194 && i < 4096)
		{
			color = (k = karettta(i)) ? k + 10 : g_gen.v_field[i];
			color = (color) ? color : 5;
			wattron(v->main, COLOR_PAIR(color));
			mvwprintw(v->main, y, x, "%02x", g_gen.field[i]);
			wattroff(v->main, COLOR_PAIR(color));
			i++;
		}
		y++;
	}
	wrefresh(v->main);
}

void	vs_prepare_stat(t_vis *v)
{
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 1, 20, "*** STATISTICS ***");
	wattroff(v->stat, COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 3, 2, "Execution status: running");
	wattroff(v->stat, A_BOLD);
	wattron(v->stat, A_UNDERLINE);
	mvwprintw(v->stat, 3, 20, "running");
	wattroff(v->stat, A_UNDERLINE);
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 5, 2, "Cycle:");
	mvwprintw(v->stat, 7, 2, "Processes:");
	mvwprintw(v->stat, 9, 2, "Carries alive:");
	mvwprintw(v->stat, 36, 2, "Cycles to die:      / %d", CYCLE_TO_DIE);
	wattroff(v->stat, A_BOLD);
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

	ft_bzero(&v, 8);
	vs_init_screen(&v);
	vs_prepare_main(&v);
	vs_prepare_stat(&v);
	vs_print_players(&v);

	st.v = v;
	// while (c != 'q')
	// {
	// 	c = wgetch(v.main);
	// }
	//
	// endwin();

}
/*
int main()
{
	vs_main();
	return (1);
}
*/
