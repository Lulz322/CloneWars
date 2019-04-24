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

void		vs_print_42(t_vis *v)
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