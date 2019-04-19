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
		if (_CHECK_WAIT)
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

void logs(int i, int d) {
	ft_printf("It is now cycle %llu, after check %i\n", i, d);
}

void	full_game()
{
	while (st.kareta)
	{
		_LOG(st.cycles + 1, st.cycles_after_check + 1);
		_PBF;
		run_cycle();
		//ft_printf("%llu", g_gen.champ[1].last_alive);
		vs_update_stats(&st.v);
		vs_update_main(&st.v);
		if (_AM_I_DIE)
			check_who_die();
	}
}

void set_karetu()
{
	st.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	_CHECK_VISUALISATION;
	full_game();
}
