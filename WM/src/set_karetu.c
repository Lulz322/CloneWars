#include "../includes/vm.h"

int		find_adress(int i)
{
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}


int		make_step(t_kareta *kareta, t_operation *operation)
{
	int		i;
	int		step;

	i = -1;
	step = 0;
	step += 1 + (operation->args_types_code ? 1 : 0);
	while (++i < g_op[kareta->code - 1].args_num)
		step += count_step(kareta->argc_types[i], operation);
	return (step);
}

void	set_operation(t_kareta *kareta)
{
	kareta->code = st.field[kareta->pos];
	if (st.field[kareta->pos] >= 0x01 && st.field[kareta->pos] <= 0x10)
		kareta->wait = g_op[kareta->code - 1].cycles;
}

void	check_karetu(t_kareta *kareta)
{
	t_operation	*new;

	if (!kareta->wait)
		set_operation(kareta);
	if (kareta->wait > 0)
		kareta->wait--;
	if (!kareta->wait)
	{
		new = NULL;
		if (kareta->code >= 0x01 && kareta->code <= 0x10)
			new = &g_op[kareta->code - 1];
		if (new)
		{
			read_argtype(kareta, new);
			if (validate_args(kareta, new) && check_args(kareta, new))
				new->func(kareta);
			else
				kareta->step += make_step(kareta, new);
		}
		else
			kareta->step = 1;
	}
	next_op(kareta);
}

void	run_cycle()
{
	t_kareta *tmp;

	_PREPARE(tmp);
	while (tmp)
	{
		check_karetu(tmp);
		tmp = tmp->next;
	}
}

void	full_game()
{
	t_gen a;

	a = g_gen;

	while (st.kareta)
	{
		if (st.log == 2)
			ft_printf("It is now cycle %llu, after check %i\n",
					st.cycles + 1, st.cycles_after_check + 1);
		if (st.flag_dump_d == st.cycles && (st.flag_dump == true || st.flag_d))
			_PRINT_B;
		run_cycle();
		a = g_gen;
		if (st.cycles_to_die == st.cycles_after_check ||
				st.cycles_to_die <= 0)
			check_who_die();
	}
}

void set_karetu()
{
	printf("DUMP :%d  | D : %d	\n", st.flag_dump, st.flag_d);
	st.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	if (st.flag_visual == true)
		vs_main();
	full_game();
}
