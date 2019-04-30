#include "../../includes/vm.h"

void				live(t_kareta *kareta)
{
	int		id;
	t_champ	*champ;

	kareta->step += OP_LEN;
	_LIVE;
	kareta->last_alive = st.cycles;
	if (id <= -1 && id >= -st.am_champs)
	{
		if (id < 0)
			id *= -1;
		_LIVE2;
		_LIVE3;
		if (st.log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, champ->name);
	}
}

void				ld(t_kareta *kareta)
{
	int32_t	value;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	_LD;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	_LD2;
}

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

void				add(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += OP_LEN + ARG_LEN;
	_ADD(reg1);
	_ADD(reg2);
	i = kareta->reg[reg1 - 1] + kareta->reg[reg2 - 1];
	kareta->carry = !i;
	_ADD(reg3);
	kareta->reg[reg3 - 1] = i;
}

void				sub(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += (OP_LEN + ARG_LEN);
	_ADD(reg1);
	_ADD(reg2);
	i = kareta->reg[reg1 - 1] + kareta->reg[reg2 - 1];
	kareta->carry = !i;
	_ADD(reg3);
	kareta->reg[reg3 - 1] = i;
}
