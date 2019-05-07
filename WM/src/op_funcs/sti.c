#include "../../includes/vm.h"

void				sti(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	value;
	int32_t	arg2;
	int32_t	arg3;

	kareta->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	value = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	arg2 = take_op(kareta, 2, 1);
	arg3 = take_op(kareta, 3, 1);
	int_to_byte(kareta->pos + (arg2 + arg3) % IDX_MOD, value, DIR_SIZE);
	set_field(kareta->pos + (arg2 + arg3) % IDX_MOD,
			st.v_field[kareta->pos], DIR_SIZE);
}
