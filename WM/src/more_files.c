#include "../includes/vm.h"

bool		is_dat_is_a_child(int i)
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

void		logs(int i, int d)
{
	ft_printf("It is now cycle %llu, after check %i\n", i, d);
}
