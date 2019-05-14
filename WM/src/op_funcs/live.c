/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:55:05 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:55:05 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				live(t_kareta *kareta)
{
	int		id;
	t_champ	*champ;

	kareta->step += OP_LEN;
	id = what_opp(kareta, 1, 0);
	ST.live_in++;
	kareta->last_alive = ST.cycles;
	champ = NULL;
	if (id <= -1 && id >= -ST.am_champs)
	{
		if (id < 0)
			id *= -1;
		champ = &ST.champ[id - 1];
		champ->last_alive = ST.cycles;
		champ->live++;
		ST.last_alive = id - 1;
		if (ST.log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, champ->name);
}
}
