#include "../includes/vm.h"

void				op_and(t_kareta *cursor)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	v;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	v1 = take_op(cursor, 1, 1);
	v2 = take_op(cursor, 2, 1);
	v = v1 & v2;
	cursor->carry = !v;
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = v;
	cursor->step += REG_LEN;
}

void				op_or(t_kareta *cursor)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	res;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	v1 = take_op(cursor, 1, 1);
	v2 = take_op(cursor, 2, 1);
	res = v1 | v2;
	cursor->carry = !res;
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = res;
	cursor->step += REG_LEN;
}

void				op_xor(t_kareta *cursor)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	res;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	v1 = take_op(cursor, 1, 1);
	v2 = take_op(cursor, 2, 1);
	res = v1 ^ v2;
	cursor->carry = !res;
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = res;
	cursor->step += REG_LEN;
}

void				op_zjmp(t_kareta *cursor)
{
	int32_t addr;

	cursor->step += OP_LEN;
	addr = take_op(cursor, 1, true);
	if (cursor->carry)
	{
		cursor->pos = find_adress(cursor->pos + (addr % IDX_MOD));
		cursor->step = 0;
	}
}

void				op_ldi(t_kareta *cursor)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	a1 = take_op(cursor, 1, 1);
	a2 = take_op(cursor, 2, 1);
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = byte_to_int((cursor->pos +
				((a1 + a2) % IDX_MOD)), DIR_SIZE);
	cursor->step += REG_LEN;
}
