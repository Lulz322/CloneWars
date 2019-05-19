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

void				live_help(int id, t_champ *champ)
{
	if (g_gen.log == 1)
		ft_printf("A process shows that player %d (%s) is alive\n",
			id, champ->name);
}

void				live(t_kareta *kareta)
{
	int		id;
	t_champ	*champ;

	kareta->step += OP_LEN;
	id = what_opp(kareta, 1, 0);
	g_gen.live_in++;
	kareta->last_alive = g_gen.cycles;
	if (id <= -1 && id >= -g_gen.am_champs)
	{
		if (id < 0)
			id *= -1;
		champ = &g_gen.champ[id - 1];
		champ->live++;
		champ->last_alive = g_gen.cycles;
		g_gen.last_alive = id - 1;
	}
	else
		champ = NULL;
	live_help(id, champ);
}
