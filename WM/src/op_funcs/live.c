#include "../../includes/vm.h"

void				live(t_kareta *kareta)
{
	int		id;
	t_champ	*champ;

	kareta->step += OP_LEN;
	_LIVE;
	kareta->last_alive = st.cycles;
	if (id <= -1 && id >= -st.am_champs)
	{
		if (id < 0)
			id *= -1;
		_LIVE2;
		_LIVE3;
		if (st.log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, champ->name);
	}
}
