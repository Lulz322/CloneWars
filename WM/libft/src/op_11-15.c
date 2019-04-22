#include "../../includes/vm.h"

void				op_sti(t_kareta *kareta)
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

void				op_fork(t_kareta *kareta)
{
	int32_t		addr;
	t_kareta	*new;

	kareta->step += OP_LEN;
	addr = take_op(kareta, 1, 1);
	new = copy_kareta(kareta, addr % IDX_MOD);
	new->next = st.kareta;
	st.kareta = new;
	st.am_karet++;
	Jason_Born();
}

void				op_lld(t_kareta *kareta)
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

void				op_lldi(t_kareta *kareta)
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

void				op_lfork(t_kareta *kareta)
{
	int32_t		addr;
	t_kareta	*new;

	kareta->step += OP_LEN;
	addr = take_op(kareta, 1, 1);
	new = copy_kareta(kareta, addr);
	new->next = st.kareta;
	st.kareta = new;
	st.am_karet++;
	Jason_Born();
}
