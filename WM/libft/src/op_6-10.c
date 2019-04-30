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

void				xor(t_kareta *kareta)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	res;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	v1 = take_op(kareta, 1, 1);
	v2 = take_op(kareta, 2, 1);
	res = v1 ^ v2;
	kareta->carry = !res;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = res;
	kareta->step += REG_LEN;
}

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

void				ldi(t_kareta *kareta)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	a1 = take_op(kareta, 1, 1);
	a2 = take_op(kareta, 2, 1);
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = byte_to_int((kareta->pos +
				((a1 + a2) % IDX_MOD)), DIR_SIZE);
	kareta->step += REG_LEN;
}
