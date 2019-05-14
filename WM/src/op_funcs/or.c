/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:11 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:54:12 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				or(t_kareta *kareta)
{
	int32_t	v1;
	int32_t	v2;
	int32_t	res;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	v1 = what_opp(kareta, 1, 1);
	v2 = what_opp(kareta, 2, 1);
	res = v1 | v2;
	kareta->carry = !res;
	reg = ST.field[adress(kareta->pos + kareta->step)];
	kareta->reg[reg - 1] = res;
	kareta->step += REG_LEN;
}
