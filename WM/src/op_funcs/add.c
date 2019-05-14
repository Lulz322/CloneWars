/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:05 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:06 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				add(t_kareta *kareta)
{
	int32_t	reg1;
	int32_t	reg2;
	int32_t	reg3;
	int32_t	i;

	kareta->step += OP_LEN + ARG_LEN;
	reg1 = ST.field[adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	reg2 = ST.field[adress(kareta->pos + kareta->step)];
	kareta->step += REG_LEN;
	i = kareta->reg[reg1 - 1] + kareta->reg[reg2 - 1];
	kareta->carry = !i;
	reg3 = ST.field[adress(kareta->pos + kareta->step)];
	kareta->reg[reg3 - 1] = i;
	kareta->step += REG_LEN;
}
