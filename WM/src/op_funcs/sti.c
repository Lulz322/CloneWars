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

int32_t				sti_sum(t_kareta *kareta)
{
	int32_t	a;
	int32_t	b;

	a = what_opp(kareta, 2, 1);
	b = what_opp(kareta, 3, 1);
	return (a + b);
}

void				sti(t_kareta *kareta)
{
	int32_t	value;
	int32_t sum;

	kareta->step += OP_LEN + ARG_LEN;
	value = kareta->reg[set_reg(kareta) - 1];
	sum = sti_sum(kareta);
	int_to_byte(kareta->pos + (sum) % IDX_MOD, value, DIR_SIZE);
	set_field(kareta->pos + (sum) % IDX_MOD,
		g_gen.v_field[kareta->pos], DIR_SIZE);
}
