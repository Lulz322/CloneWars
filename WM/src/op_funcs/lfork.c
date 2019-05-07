#include "../../includes/vm.h"

void				lfork(t_kareta *kareta)
{
	int32_t		addr;
	t_kareta	*new;

	kareta->step += OP_LEN;
	addr = take_op(kareta, 1, 1);
	new = copy_kareta(kareta, addr);
	REPLACE;
	jason_born();
}
