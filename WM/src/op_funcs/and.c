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

int32_t				to_and(int32_t a, int32_t b)
{
	return (a & b);
}

void				and(t_kareta *kareta)
{
	int32_t	qqq;

	kareta->step += OP_LEN + ARG_LEN;
	qqq = to_and(what_opp(kareta, 1, 1), what_opp(kareta, 2, 1));
	kareta->carry = !qqq;
	kareta->reg[set_reg(kareta) - 1] = qqq;
}
