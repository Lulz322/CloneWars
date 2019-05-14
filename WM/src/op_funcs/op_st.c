/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:06 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:54:07 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				op_st(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	i;
	int32_t	addr;

	kareta->step += OP_LEN + ARG_LEN;
	reg = ST.field[adress(kareta->pos + kareta->step)];
	STBLYAT;
	if (kareta->argc_types[1] == T_REG)
	{
		SSST;
	}
	else
	{
		addr = byte_to_int(kareta->pos + kareta->step, IND_SIZE);
		int_to_byte(kareta->pos + (addr % IDX_MOD), i, DIR_SIZE);
		kareta->step += IND_SIZE;
		set_field(kareta->pos + addr % IDX_MOD,
				ST.v_field[kareta->pos], DIR_SIZE);
	}
}
