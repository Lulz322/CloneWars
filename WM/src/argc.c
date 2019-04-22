#include "../includes/vm.h"

int8_t	count_size(int pos, int step)
{
	int8_t reg;

	reg = st.field[find_adress(pos + step)];
	return (reg >= 1 && reg <= REG_NUMBER);
}

int		count_step(uint8_t type, t_operation *oop)
{
	if (type & T_REG)
		return (T_REG);
	else if (type & T_DIR)
		return (oop->t_dir_size);
	else if (type & T_IND)
		return (IND_SIZE);
	return (0);
}

int		check_args(t_kareta *kareta, t_operation *oop)
{
	int		i;
	int		step;

	i = 0;
	step = (1 + (oop->args_types_code ? 1 : 0));
	while (i < oop->args_num)
	{
		if ((kareta->argc_types[i] == T_REG)
			&& !count_size(kareta->pos, step))
			return (0);
		step += count_step(kareta->argc_types[i], oop);
		i++;
	}
	return (1);
}

bool	validate_args(t_kareta *kareta, t_operation *oop)
{
	int i;

	i = -1;
	while (++i < oop->args_num)
		if (!(kareta->argc_types[i] & oop->args_types[i]))
			return (false);
	return (true);
}

void	read_argtype(t_kareta *kareta, t_operation *oop)
{
	int8_t atc;

	if (oop->args_types_code)
	{
		atc = st.field[find_adress(kareta->pos + 1)];
		if (oop->args_num >= 1)
			kareta->argc_types[0] = g_arg_code[((atc & 0xC0) >> 6) - 1];
		if (oop->args_num >= 2)
			kareta->argc_types[1] = g_arg_code[((atc & 0x30) >> 4) - 1];
		if (oop->args_num >= 3)
			kareta->argc_types[2] = g_arg_code[((atc & 0xC) >> 2) - 1];
	}
	else
		kareta->argc_types[0] = oop->args_types[0];
}
