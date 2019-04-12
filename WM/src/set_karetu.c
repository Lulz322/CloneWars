#include "../includes/vm.h"

void print_info_champs()
{
	int a;

	a = -1;
	ft_printf("Introducing contestants...\n");
	while (g_gen.champ[++a].length)
		printf("* Player %d, weighing %d bytes, \"%-25.25s\" (\"%-25.25s\") !\n", a + 1, st.champ[a].length, st.champ[a].name, st.champ[a].comment);
}

void set_karetu()
{
	//print_list(st.kareta);
	print_info_champs();
}
