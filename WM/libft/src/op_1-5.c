#include "../../includes/vm.h"

void				op_live(t_kareta *kareta)
{
	int		id;
	t_champ	*champ;

	kareta->step += OP_LEN;
	id = take_op(kareta, 1, 0);
	st.live_in++;
	kareta->last_alive = st.cycles;
	champ = NULL;
	if (id <= -1 && id >= -st.am_champs)
	{
		if (id < 0)
			id *= -1;
		champ = &st.champ[id - 1];
		champ->last_alive = st.cycles;
		champ->live++;
		st.last_alive = id - 1;
		if (st.log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, champ->name);
	}
}

void				op_ld(t_kareta *kareta)
{
	int32_t	value;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	value = take_op(kareta, 1, 1);
	kareta->carry = !value;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = value;
	kareta->step += REG_LEN;
}

void				op_st(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	i;
	int32_t	addr;

	kareta->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	i = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	if (kareta->argc_types[1] == T_REG)
	{
		addr = st.field[find_adress(kareta->pos + kareta->step)];
		kareta->reg[addr - 1] = i;
		kareta->step += REG_LEN;
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

void				op_add(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += OP_LEN + ARG_LEN;
	reg1 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	reg2 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	i = kareta->reg[reg1 - 1] + kareta->reg[reg2 - 1];
	kareta->carry = !i;
	reg3 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg3 - 1] = i;
	kareta->step += REG_LEN;
}

void				op_sub(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += (OP_LEN + ARG_LEN);
	reg1 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	reg2 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	i = kareta->reg[reg1 - 1] - kareta->reg[reg2 - 1];
	kareta->carry = !i;
	reg3 = st.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg3 - 1] = i;
	kareta->step += REG_LEN;
}
