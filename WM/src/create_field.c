#include "../includes/vm.h"

void print_field() {
	int a;
	int j;

	a = 0;
	while (a < MEM_SIZE)
	{
		ft_printf("%.4p : ", a);
		j = 0;
		while (j < 32)
		{
			ft_printf("%.2x ", g_gen.field[a + j]);
			j++;
		}
		ft_printf("\n");
		a += 32;
	}
}

void print_player_code() {
	int a;
	int j;

	a = -1;
	while (++a < 4 && g_gen.champ[a].name[0])
	{
		j = -1;
		while(++j < g_gen.champ[a].length)
			printf("%02x ", g_gen.champ[a].algo[j]);
		printf("\n\n\n");
	}
}

void set_players(t_champ champ, int byte) {
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < MEM_SIZE && i < byte)
		i++;
	while (j < champ.length)
		g_gen.field[i++] = champ.algo[j++];
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
	print_player_code();
	a = how_many_players();
	a = MEM_SIZE / a;
	while (i < MEM_SIZE)
	{
		set_players(g_gen.champ[j++], i);
		add_elem(&st.kareta, i);
		i += a;
	}
	print_field();
}
