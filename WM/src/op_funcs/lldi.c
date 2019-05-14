/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:58 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:59 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				lldi(t_kareta *kareta)
{
	int32_t	a1;
	int32_t	a2;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	a1 = take_op(kareta, 1, 1);
	a2 = take_op(kareta, 2, 1);
	reg = ST.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = byte_to_int(kareta->pos + a1 + a2, DIR_SIZE);
	kareta->step += REG_LEN;
}
