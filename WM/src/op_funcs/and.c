/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:12 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:32 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				and(t_kareta *kareta)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	v;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	v1 = what_opp(kareta, 1, 1);
	v2 = what_opp(kareta, 2, 1);
	v = v1 & v2;
	kareta->carry = !v;
	reg = g_gen.field[adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = v;
	kareta->step += REG_LEN;
}
