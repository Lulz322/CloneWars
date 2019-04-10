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

void create_field(void) {
	int a;

	a = 0;
	print_player_code();
	//ft_bzero(g_gen.field, MEM_SIZE);
	//print_field();
}
