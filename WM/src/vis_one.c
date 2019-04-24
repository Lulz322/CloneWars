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


void	vs_corewar(WINDOW *win)
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

void	vs_42_one(t_vis *v)
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


void	vs_42_two(t_vis *v)
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



void	vs_print_42(t_vis *v)
{
	static int i;
	int mod;

	mod = 110;
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
		(i == 1) ? vs_42_one(v) : vs_42_two(v);
		i++;
		i = (i > 2) ? 1 : i;
	}
}


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

int	vs_init_screen(t_vis *v)
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
		write(1, "Term size is too small for the visualization\n", 45);
		return (0);
	}
	v->main = newwin(66, 195, 2, 2);
	v->stat = newwin(66, 60, 2, 198);
	return (1);
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
	vs_print_players(v);
	while (++i <= g_gen.am_champs - 1)
	{
		mvwprintw(v->stat, y + 1, 30, "%d           ", g_gen.champ[i].last_alive);
		mvwprintw(v->stat, y + 2, 30, "%d           ", g_gen.champ[i].live);
		y += 6;
	}
}
void	vs_draw_pause(t_vis *v)
{
	mvwprintw(v->stat, 3, 20, "        ");
	wattron(v->stat, A_UNDERLINE | COLOR_PAIR(RED_BLACK));
	mvwprintw(v->stat, 3, 20, "paused");
	wattroff(v->stat, A_UNDERLINE | COLOR_PAIR(RED_BLACK));
	wrefresh(v->stat);
}

void	vs_draw_speed(int speed, t_vis *v)
{
	int i;

	i = -1;
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 40, 2, "Speed rate: ");
	wattroff(v->stat, A_BOLD);
	mvwprintw(v->stat, 40, 15, "x%d", 5 - speed);
	mvwprintw(v->stat, 40, 18, "     ");
	while (++i < (5 - speed))
		mvwprintw(v->stat, 40, i + 18, ">");
}
void vs_handle_speed(int speed, t_vis *v)
{
	vs_draw_speed(speed, v);
	if (!speed)
		return ;
	else if (speed == 1)
		system("sleep 0.01");
	else if (speed == 2)
		system("sleep 0.05");
	else if (speed == 3)
		system("sleep 0.1");
	else if (speed == 4)
		system("sleep 0.2");
	else if (speed == 5)
		system("sleep 0.4");
}

void	vs_check_key_events(t_vis *v)
{
	int c;
	static int speed;

	c = getch();
	if (c == ' ' && (c = 1))
	{
		vs_draw_pause(v);
		while (c != ' ' && c != 'q')
			c = getch();
	}
	if (c == 'q')
	{
		endwin();
		exit(1);
	}
	if (c == KEY_LEFT && speed < 5)
		speed++;
	else if (c == KEY_RIGHT && speed > 0)
		speed--;
	vs_handle_speed(speed, v);
}

void	vs_update_stats(t_vis *v)
{
	float len;
	int x;
	int i;

	i = 0;
	x = 3;
	vs_prepare_stat(v);
	len = (float)(CYCLE_TO_DIE / 27) - (float)(g_gen.cycles_to_die / 27);
	vs_check_key_events(v);
	mvwprintw(v->stat, 5, 20, "%d      ", g_gen.cycles);
	mvwprintw(v->stat, 7, 20, "%d      ", g_gen.cycles_after_check);
	mvwprintw(v->stat, 9, 20, "%d      ", g_gen.am_karet);
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 38, 2, KOLBASKA);
	while (i < (int)len && i < 54)
	{
		mvwprintw(v->stat, 38, x, "#");
		i++;
		x++;
	}
	vs_print_42(v);
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
	box(v->main, 0, 0);
	box(v->stat, 0, 0);
	while (y < 65 && i < 4096)
	{
		x = -1;
		while ((x += 3) < 194 && i < 4096)
		{
			color = (k = karettta(i)) ? k + 10 : g_gen.v_field[i];
			color += (k && is_dat_is_a_child(i) == true) ? 10 : 0;
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
	mvwprintw(v->stat, 3, 2, "Execution status:");
	wattroff(v->stat, A_BOLD);
	wattron(v->stat, A_UNDERLINE | COLOR_PAIR(GREEN_BLACK));
	mvwprintw(v->stat, 3, 20, "running");
	wattroff(v->stat, A_UNDERLINE | COLOR_PAIR(GREEN_BLACK));
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 5, 2, "Cycle:");
	mvwprintw(v->stat, 7, 2, "Processes:");
	mvwprintw(v->stat, 9, 2, "Carries alive:");
	mvwprintw(v->stat, 36, 2, "Cycles to die: %d", CYCLE_TO_DIE);
	mvwprintw(v->stat, 42, 2, "CYCLE_DELTA: ");
	mvwprintw(v->stat, 43, 2, "NBR_LIVE: ");
	mvwprintw(v->stat, 44, 2, "MAX_CHECKS: ");
	wattroff(v->stat, A_BOLD);
	mvwprintw(v->stat, 42, 15, "%d", CYCLE_DELTA);
	mvwprintw(v->stat, 43, 15, "%d", NBR_LIVE);
	mvwprintw(v->stat, 44, 15, "%d", MAX_CHECKS);
	wattron(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 2, "Created by:");
	wattroff(v->stat, A_BOLD | COLOR_PAIR(YELLOW_BLACK));
	mvwprintw(v->stat, 64, 14, "iruban, mbiliaie, dlenskyi, amatveie");
	wrefresh(v->stat);
}

void	vs_prepare_winer(int *y, int *x, int *len)
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
	*len = ft_strlen(st.champ[st.last_alive].name);
	refresh();
}

void		vs_announce_winner(int i, int j, int o)
{
	int y;
	int x;
	int len;

	i = 1;
	vs_prepare_winer(&y, &x, &len);
	attron(COLOR_PAIR(st.last_alive + 1));
	while (i < y - 1)
	{
		j = 2;
		while (j < x - 1)
		{
			if (o - 1 == len)
				o = 0;
			mvprintw(i, j, "%c", st.champ[st.last_alive].name[o]);
			j += 2;
			o++;
		}
		i++;
	}
	attroff(COLOR_PAIR(st.last_alive + 1));
	refresh();
	vs_print_banner(y, x);
	//getch();
	//endwin();
}

void	vs_main(void)
{
	t_vis v;

	ft_bzero(&v, 8);
	if (vs_init_screen(&v))
	{
		vs_prepare_main(&v);
		vs_prepare_stat(&v);
		vs_print_players(&v);
		st.v = v;
	}
	else
	{
		st.flag_visual = false;
	}
}