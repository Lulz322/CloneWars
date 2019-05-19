/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:54:25 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:54:26 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				zjmp(t_kareta *kareta)
{
	int32_t addr;

	kareta->step += OP_LEN;
	addr = what_opp(kareta, 1, true);
	if (kareta->carry)
	{
		kareta->pos = adress(kareta->pos + (addr % IDX_MOD));
		kareta->step = 0;
	}
}
