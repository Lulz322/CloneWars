/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:55:10 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:55:11 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				sti(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	value;
	int32_t	arg2;
	int32_t	arg3;

	kareta->step += OP_LEN + ARG_LEN;
	reg = g_gen.field[adress(kareta->pos + kareta->step)];
	value = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	arg2 = what_opp(kareta, 2, 1);
	arg3 = what_opp(kareta, 3, 1);
	int_to_byte(kareta->pos + (arg2 + arg3) % IDX_MOD, value, DIR_SIZE);
	set_field(kareta->pos + (arg2 + arg3) % IDX_MOD,
			g_gen.v_field[kareta->pos], DIR_SIZE);
}
