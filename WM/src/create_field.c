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

void		set_field(int32_t addr, uint8_t i, int32_t size)
{
	int j;

	j = 0;
	while (size)
	{
		st.v_field[find_adress(addr + size - 1)] = i;
		j += 8;
		size--;
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
