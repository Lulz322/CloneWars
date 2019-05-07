#include "../../includes/vm.h"

void				op_st(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	i;
	int32_t	addr;

	kareta->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	_ST;
	if (kareta->argc_types[1] == T_REG)
	{
		_SSST;
	}
	else
	{
		addr = byte_to_int(kareta->pos + kareta->step, IND_SIZE);
		int_to_byte(kareta->pos + (addr % IDX_MOD), i, DIR_SIZE);
		kareta->step += IND_SIZE;
		set_field(kareta->pos + addr % IDX_MOD,
				st.v_field[kareta->pos], DIR_SIZE);
	}
}
