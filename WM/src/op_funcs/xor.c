/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:21 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:54:22 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int32_t				xor_set(int32_t a, int32_t b)
{
	return (a ^ b);
}

void				xor(t_kareta *kareta)
{
	int32_t	res;

	kareta->step += OP_LEN + ARG_LEN;
	res = xor_set(what_opp(kareta, 1, 1), what_opp(kareta, 2, 1));
	kareta->carry = !res;
	kareta->reg[set_reg(kareta) - 1] = res;
}
