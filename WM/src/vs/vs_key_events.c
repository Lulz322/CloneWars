#include "../includes/vm.h"

static void	vs_draw_pause(t_vis *v)
{
	mvwprintw(v->stat, 3, 20, "             ");
	wattron(v->stat, A_UNDERLINE | COLOR_PAIR(RED_BLACK));
	mvwprintw(v->stat, 3, 20, ((st.f_p) ? "зупинка" : "paused"));
	wattroff(v->stat, A_UNDERLINE | COLOR_PAIR(RED_BLACK));
	wrefresh(v->stat);
}

static void	vs_draw_speed(int speed, t_vis *v)
{
	int i;

	i = -1;
	wattron(v->stat, A_BOLD);
	mvwprintw(v->stat, 40, 2, ((st.f_p) ? "Швидкість: " : "Speed rate: "));
	wattroff(v->stat, A_BOLD);
	mvwprintw(v->stat, 40, 15, "x%d", 5 - speed);
	mvwprintw(v->stat, 40, 18, "     ");
	while (++i < (5 - speed))
		mvwprintw(v->stat, 40, i + 18, ">");
}

static void vs_handle_speed(int speed, t_vis *v)
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