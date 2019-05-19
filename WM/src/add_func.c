/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:35:53 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 11:35:54 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			what_opp(t_kareta *kareta, uint8_t i, int mod)
{
	t_operation	*op;
	int			value;
	int			addr;

	op = &g_op[kareta->code - 1];
	value = 0;
	if (kareta->argc_types[i - 1] & T_REG)
		value = kareta->reg[g_gen.field[adress(kareta->pos +
				kareta->step)] - 1];
	else if (kareta->argc_types[i - 1] & T_DIR)
		value = byte_to_int(kareta->pos + kareta->step, op->t_dir_size);
	else if (kareta->argc_types[i - 1] & T_IND)
	{
		addr = byte_to_int(kareta->pos + kareta->step, IND_SIZE);
		value = byte_to_int(kareta->pos + (mod ? (addr % IDX_MOD) :
					addr), DIR_SIZE);
	}
	kareta->step += how_m_steps(kareta->argc_types[i - 1], op);
	return (value);
}

void		swap(t_champ *first, t_champ *second)
{
	t_champ tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

int			check_where(char *where)
{
	int		a;
	char	*tmp;

	if (!where)
		ERROR("O_o");
	a = ft_atoi(where);
	tmp = ft_itoa(a);
	if (!ft_strequ(tmp, where))
	{
		free(tmp);
		ERROR("Enter a number!");
	}
	free(tmp);
	return (a);
}

int			adress(int i)
{
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}

int32_t		set_reg(t_kareta *kareta)
{
	int32_t	tmp;

	tmp = g_gen.field[adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	return (tmp);
}
