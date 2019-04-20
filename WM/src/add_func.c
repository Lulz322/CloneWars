#include "../includes/vm.h"

void		op_aff(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	value;

	kareta->step += OP_LEN + ARG_LEN;
	reg = st.field[find_adress(kareta->pos + kareta->step)];
	value = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	if (st.aff)
		ft_printf("%c\n", (char)value);
}

void		set_field(int32_t addr, uint8_t i, int32_t size)
{
	int j;

	j = 0;
	while (size)
	{
		st.v_field[find_adress(addr + size - 1)] = i;
		j += 8;
		size--;
	}
}

void		int_to_byte(int32_t addr, int32_t value, int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		st.field[find_adress(addr + size - 1)] =
			(uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int32_t		byte_to_int(int32_t addr, int32_t size)
{
	int32_t		result;
	uint8_t		sign;
	int			i;

	i = 0;
	result = 0;
	sign = (st.field[find_adress(addr)] & 0x80);
	while (size)
	{
		if (sign)
			result += ((st.field[find_adress(addr + size - 1)] ^ 0xFF) <<
					(i++ * 8));
		else
			result += st.field[find_adress(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int			take_op(t_kareta *kareta, uint8_t i, int mod)
{
	t_operation	*op;
	int			value;
	int			addr;

	op = &g_op[kareta->code - 1];
	value = 0;
	if (kareta->argc_types[i - 1] & T_REG)
		value = kareta->reg[st.field[find_adress(kareta->pos +
				kareta->step)] - 1];
	else if (kareta->argc_types[i - 1] & T_DIR)
		value = byte_to_int(kareta->pos + kareta->step, op->t_dir_size);
	else if (kareta->argc_types[i - 1] & T_IND)
	{
		addr = byte_to_int(kareta->pos + kareta->step, IND_SIZE);
		value = byte_to_int(kareta->pos + (mod ? (addr % IDX_MOD) :
					addr), DIR_SIZE);
	}
	kareta->step += count_step(kareta->argc_types[i - 1], op);
	return (value);
}
