#include "../../includes/vm.h"

void				and(t_kareta *kareta)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	v;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	v1 = take_op(kareta, 1, 1);
	v2 = take_op(kareta, 2, 1);
	v = v1 & v2;
	kareta->carry = !v;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = v;
	kareta->step += REG_LEN;
}
