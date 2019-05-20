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

int32_t				or_set(int32_t a, int32_t b)
{
	return (a | b);
}

void				or(t_kareta *kareta)
{
	int32_t	res;

	kareta->step += OP_LEN + ARG_LEN;
	res = or_set(what_opp(kareta, 1, 1), what_opp(kareta, 2, 1));
	kareta->carry = !res;
	kareta->reg[set_reg(kareta) - 1] = res;
}
