/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:59 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:55:00 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				lld(t_kareta *kareta)
{
	int32_t	v;
	int32_t	reg;

	kareta->step += (OP_LEN + ARG_LEN);
	v = what_opp(kareta, 1, 0);
	kareta->carry = !v;
	reg = ST.field[find_adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = v;
	kareta->step += REG_LEN;
}
