/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:16 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:54:17 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				sub(t_kareta *kareta)
{
	kareta->step += OP_LEN + ARG_LEN;
	kareta->carry = !(kareta->reg[set_reg(kareta) - 1]
					- kareta->reg[set_reg(kareta) - 1]);
	kareta->reg[set_reg(kareta) - 1] = !kareta->carry;
}
