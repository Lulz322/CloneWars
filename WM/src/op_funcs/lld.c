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
	kareta->step += OP_LEN + ARG_LEN;
	kareta->carry = !what_opp(kareta, 1, 0);
	kareta->reg[set_reg(kareta) - 1] = what_opp(kareta, 1, 0);
}
