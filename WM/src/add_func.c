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

void swap(t_champ *first, t_champ *second)
{
	t_champ tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int check_where(char *where)
{
	int a;
	char *tmp;

	if (!where)
		_ERROR("O_o");
	a = ft_atoi(where);
	tmp = ft_itoa(a);
	if (!ft_strequ(tmp, where))
	{
		free(tmp);
		_ERROR("Enter a number!");
	}
	free(tmp);
	return (a);
}

int		find_adress(int i)
{
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}
