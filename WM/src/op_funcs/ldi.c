/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:46 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:47 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				ldi(t_kareta *kareta)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	a1 = what_opp(kareta, 1, 1);
	a2 = what_opp(kareta, 2, 1);
	reg = g_gen.field[adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = byte_to_int((kareta->pos +
				((a1 + a2) % IDX_MOD)), DIR_SIZE);
	kareta->step += REG_LEN;
}
