#include "../includes/vm.h"

void				op_sti(t_kareta *cursor)
{
	int32_t	reg;
	int32_t	value;
	int32_t	arg2;
	int32_t	arg3;

	cursor->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	value = cursor->reg[reg - 1];
	cursor->step += REG_LEN;
	arg2 = take_op(cursor, 2, 1);
	arg3 = take_op(cursor, 3, 1);
	int_to_byte(cursor->pos + (arg2 + arg3) % IDX_MOD, value, DIR_SIZE);
	set_field(cursor->pos + (arg2 + arg3) % IDX_MOD,
			st.v_field[cursor->pos], DIR_SIZE);
}

void				op_fork(t_kareta *cursor)
{
	int32_t		addr;
	t_kareta	*new;

	cursor->step += OP_LEN;
	addr = take_op(cursor, 1, 1);
	new = copy_kareta(cursor, addr % IDX_MOD);
	new->next = st.kareta;
	st.kareta = new;
	st.am_karet++;
}

void				op_lld(t_kareta *cursor)
{
	int32_t	v;
	int32_t	reg;

	cursor->step += (OP_LEN + ARG_LEN);
	v = take_op(cursor, 1, 0);
	cursor->carry = !v;
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = v;
	cursor->step += REG_LEN;
}

void				op_lldi(t_kareta *cursor)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	cursor->step += OP_LEN + ARG_LEN;
	a1 = take_op(cursor, 1, 1);
	a2 = take_op(cursor, 2, 1);
	reg = st.field[find_adress(cursor->pos + cursor->step)];
	cursor->reg[reg - 1] = byte_to_int(cursor->pos + a1 + a2, DIR_SIZE);
	cursor->step += REG_LEN;
}

void				op_lfork(t_kareta *cursor)
{
	int32_t		addr;
	t_kareta	*new;

	cursor->step += OP_LEN;
	addr = take_op(cursor, 1, 1);
	new = copy_kareta(cursor, addr);
	new->next = st.kareta;
	st.kareta = new;
	st.am_karet++;
}
