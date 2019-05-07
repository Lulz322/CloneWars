#include "../../includes/vm.h"

void				lld(t_kareta *kareta)
{
	int32_t	v;
	int32_t	reg;

	kareta->step += (OP_LEN + ARG_LEN);
	v = take_op(kareta, 1, 0);
	kareta->carry = !v;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = v;
	kareta->step += REG_LEN;
}
