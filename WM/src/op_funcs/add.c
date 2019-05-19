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

int32_t to_steps(t_kareta *kareta, int32_t a, int32_t b)
{
	return (kareta->reg[a - 1] + kareta->reg[b - 1]);
}

void				add(t_kareta *kareta)
{
	int32_t	reg3;
	int32_t	i;

	kareta->step += OP_LEN + ARG_LEN;
	i = to_steps(kareta, set_reg(kareta), set_reg(kareta));
	kareta->carry = !i;
	reg3 = set_reg(kareta);
	kareta->reg[reg3 - 1] = i;
}
