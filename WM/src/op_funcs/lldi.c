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
	kareta->step += OP_LEN + ARG_LEN;
	kareta->reg[set_reg(kareta) - 1] = byte_to_int(kareta->pos +
		what_opp(kareta, 1, 1) + what_opp(kareta, 2, 1),
			DIR_SIZE);
}
