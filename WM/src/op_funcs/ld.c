/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:35 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:36 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				ld(t_kareta *kareta)
{
	int32_t	value;

	kareta->step += OP_LEN + ARG_LEN;
	value = what_opp(kareta, 1, 1);
	kareta->carry = !value;
	kareta->reg[set_reg(kareta) - 1] = value;
}
