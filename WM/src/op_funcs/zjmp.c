#include "../../includes/vm.h"

void				zjmp(t_kareta *kareta)
{
	int32_t addr;

	kareta->step += OP_LEN;
	addr = take_op(kareta, 1, true);
	if (kareta->carry)
	{
		kareta->pos = find_adress(kareta->pos + (addr % IDX_MOD));
		kareta->step = 0;
	}
}
