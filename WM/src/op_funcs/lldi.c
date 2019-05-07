#include "../../includes/vm.h"

void				lldi(t_kareta *kareta)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	a1 = take_op(kareta, 1, 1);
	a2 = take_op(kareta, 2, 1);
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = byte_to_int(kareta->pos + a1 + a2, DIR_SIZE);
	kareta->step += REG_LEN;
}
