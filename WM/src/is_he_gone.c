#include "../includes/vm.h"

void	next_op(t_kareta *kareta)
{
	kareta->pos = find_adress(kareta->pos + kareta->step);
	kareta->step = 0;
	ft_bzero(kareta->argc_types, 3);
}

int		is_die(t_kareta *kareta)
{
	return (st.cycles_to_die <= 0
			|| st.cycles - kareta->last_alive >= st.cycles_to_die);
}

void	check_karetutu(t_kareta *prev)
{
	t_kareta *tmp;
	t_kareta *new;

	tmp = st.kareta;
	while (tmp)
	{
		if (is_die(tmp))
		{
			new = tmp->next;
			free(tmp);
			if (prev)
				prev->next = new;
			else
				st.kareta = new;
			tmp = new;
			st.am_karet--;
		}
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

void	check_who_die()
{
	int i;

	i = -1;
	st.check_in++;
	check_karetutu(NULL);
	if (st.check_in == MAX_CHECKS || st.live_in >= NBR_LIVE)
	{
		st.cycles_to_die -= CYCLE_DELTA;
		if (st.log == 2)
			ft_printf("Cycle to die is now %i\n", st.cycles_to_die);
		st.check_in = 0;
	}
	while (++i < st.am_champs)
	{
		st.champ[i].last_alive = st.champ[i].live;
		st.champ[i].live = 0;
	}
	st.live_in = 0;
	st.cycles_after_check = 0;
}
