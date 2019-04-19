#include "../includes/vm.h"

int karettta(int i)
{
	t_kareta *tmp;

	tmp = st.kareta;
	while (tmp)
	{
		if (tmp->pos == i && -tmp->reg[0] > 0 && -tmp->reg[0] <= st.am_champs)
			return (-tmp->reg[0]);
		tmp = tmp->next;
	}
	return (0);
}

bool is_dat_is_a_child(int i)
{

	t_kareta *tmp;

	tmp = st.kareta;
	while (tmp)
	{
		if (tmp->pos == i && tmp->living <= 50)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void print_field(int i) {
	int a;
	int j;

	a = 0;
	while (a < MEM_SIZE)
	{
		ft_printf("%.4p : ", a);
		j = 0;
		while (j < i)
		{
			if (karettta(a + j) == 1)
				ft_printf("MRED(%.2x) ", g_gen.field[a + j]);
			else if (karettta(a + j) == 2)
				ft_printf("MYLW(%.2x) ", g_gen.field[a + j]);
			else if (karettta(a + j) == 3)
				ft_printf("MPRP(%.2x) ", g_gen.field[a + j]);
			else if(karettta(a + j) == 4)
				ft_printf("MCYN(%.2x) ", g_gen.field[a + j]);
			else {
				if (g_gen.v_field[a + j] == 1)
					ft_printf("MGRN(%.2x) ", g_gen.field[a + j]);
				else if (g_gen.v_field[a + j] == 2)
					ft_printf("MBLU(%.2x) ", g_gen.field[a + j]);
				else if(g_gen.v_field[a + j] == 3)
					ft_printf("MCYN(%.2x) ", g_gen.field[a + j]);
				else if(g_gen.v_field[a + j] == 4)
					ft_printf("MYLW(%.2x) ", g_gen.field[a + j]);
				else
					ft_printf("%.2x ", g_gen.v_field[a + j]);
			}
			j++;
		}
		ft_printf("\n");
		a += i;
	}
}

void print_player_code() {
	int a;
	int j;

	a = -1;
	while (++a < 4 && g_gen.champ[a].name)
	{
		j = -1;
		while(++j < g_gen.champ[a].length)
			printf("%02x ", g_gen.champ[a].algo[j]);
		printf("\n\n\n");
	}
}

void set_players(t_champ champ, int byte)
{
	int i;
	int j;
	t_kareta *a;

	a = g_gen.kareta;
	i = 0;
	j = 0;
	while (i < MEM_SIZE && i < byte)
		i++;
	while (j < champ.length)
	{
		g_gen.field[i] = champ.algo[j++];
		g_gen.v_field[i] = -a->reg[0];
		i++;
	}
}

int how_many_players(void)
{
	int i;

	i = 0;
	while (g_gen.champ[i].length)
		i++;
	return (i);
}

void create_field(void)
{
	int a;
	int i;
	int j;

	i = 0;
	j = 0;
	g_gen.kareta = NULL;
	a = how_many_players();
	g_gen.am_champs = a;
	a = MEM_SIZE / a;
	while (i < MEM_SIZE)
	{
		add_elem(&st.kareta, i);
		set_players(g_gen.champ[j++], i);
		i += a;
	}
}
