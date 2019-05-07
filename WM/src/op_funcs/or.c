#include "../../includes/vm.h"

void				or(t_kareta *kareta)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	res;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	v1 = take_op(kareta, 1, 1);
	v2 = take_op(kareta, 2, 1);
	res = v1 | v2;
	kareta->carry = !res;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = res;
	kareta->step += REG_LEN;
}
