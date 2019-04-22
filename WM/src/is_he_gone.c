#include "../includes/vm.h"

bool	is_die(t_kareta *kareta)
{
	return (st.cycles_to_die <= 0
			|| st.cycles - kareta->last_alive >= st.cycles_to_die);
}

t_kareta *del(t_kareta **del_me, t_kareta *prev)
{
	t_kareta *new;
	t_kareta *tmp;

	tmp = *del_me;
	new = tmp->next;
	free(tmp);
	if (prev)
		prev->next = new;
	else
		st.kareta = new;
	tmp = new;
	st.am_karet--;
	//system("afplay died.wav&");
	return (tmp);
}

void	check_karetutu(t_kareta *prev)
{
	t_kareta *tmp;

	tmp = st.kareta;
	while (tmp)
	{
		if (is_die(tmp))
			tmp = del(&tmp, prev);
		else
		{
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

void 	set_zero()
{
	int i;

	i = -1;
	while (++i < st.am_champs)
	{
		st.champ[i].last_alive = st.champ[i].live;
		st.champ[i].live = 0;
	}
}

void	check_who_die()
{
	st.check_in++;
	check_karetutu(NULL);
	_IS_CYCLE;
	set_zero();
	_ZERO;
}
