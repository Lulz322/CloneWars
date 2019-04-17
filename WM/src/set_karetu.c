#include "../includes/vm.h"

int		find_adress(int i)
{
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}


int		make_step(t_kareta *cursor, t_operation *operation)
{
	int		i;
	int		step;

	i = -1;
	step = 0;
	step += 1 + (operation->args_types_code ? 1 : 0);
	while (++i < g_op[cursor->code - 1].args_num)
		step += count_step(cursor->argc_types[i], operation);
	return (step);
}

void	set_operation(t_kareta *cursor)
{
	cursor->code = st.field[cursor->pos];
	if (st.field[cursor->pos] >= 0x01 && st.field[cursor->pos] <= 0x10)
		cursor->wait = g_op[cursor->code - 1].cycles;
}

void	check_cursor(t_kareta *cursor)
{
	t_operation	*new;

	if (!cursor->wait)
		set_operation(cursor);
	if (cursor->wait > 0)
		cursor->wait--;
	if (!cursor->wait)
	{
		new = NULL;
		if (cursor->code >= 0x01 && cursor->code <= 0x10)
			new = &g_op[cursor->code - 1];
		if (new)
		{
			read_argtype(cursor, new);
			if (validate_args(cursor, new) && check_args(cursor, new))
				new->func(cursor);
			else
				cursor->step += make_step(cursor, new);
		}
		else
			cursor->step = 1;
	}
	next_op(cursor);
}

void	run_cycle()
{
	t_kareta *tmp;

	st.cycles++;
	st.cycles_after_check++;
	tmp = st.kareta;
	while (tmp)
	{
		check_cursor(tmp);
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
		if (st.flag_dump_d == st.cycles && st.flag_dump == true)
		{
			print_field();
			exit(1);
		}
		run_cycle();
		 system("clear");
		 print_field();
		 usleep(60000);
		a = g_gen;
		if (st.cycles_to_die == st.cycles_after_check ||
				st.cycles_to_die <= 0)
			check_who_die();
	}
}

void set_karetu()
{

	st.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	full_game();
}
