#include "../../includes/vm.h"

void				add(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += OP_LEN + ARG_LEN;
	_ADD(reg1);
	_ADD(reg2);
	i = kareta->reg[reg1 - 1] + kareta->reg[reg2 - 1];
	kareta->carry = !i;
	_ADD(reg3);
	kareta->reg[reg3 - 1] = i;
}
