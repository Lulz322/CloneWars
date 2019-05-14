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
	LIVE;
	kareta->last_alive = ST.cycles;
	if (id <= -1 && id >= -ST.am_champs)
	{
		if (id < 0)
			id *= -1;
		LIVE2;
		LIVE3;
		if (ST.log == 1)
			ft_printf("Player %i (%s) is said to be alive\n", id, champ->name);
	}
}
