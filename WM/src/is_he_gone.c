/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_he_gone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:42:47 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 11:42:48 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_kareta	*del(t_kareta **del_me, t_kareta *prev)
{
	t_kareta *new;
	t_kareta *tmp;

	tmp = *del_me;
	new = tmp->next;
	free(tmp);
	if (prev)
		prev->next = new;
	else
		g_gen.kareta = new;
	tmp = new;
	g_gen.am_karet--;
	set_death();
	return (tmp);
}

void		check_karetutu(void)
{
	t_kareta *tmp;
	t_kareta *no_name;

	no_name = NULL;
	tmp = g_gen.kareta;
	while (tmp)
	{
		if (g_gen.cycles_to_die <= 0
				|| g_gen.cycles - tmp->last_alive >= g_gen.cycles_to_die)
			tmp = del(&tmp, no_name);
		else
		{
			no_name = tmp;
			tmp = tmp->next;
		}
	}
}

void		set_zero(void)
{
	int i;

	i = -1;
	while (++i < g_gen.am_champs)
	{
		g_gen.champ[i].last_alive = g_gen.champ[i].live;
		g_gen.champ[i].live = 0;
	}
	g_gen.live_in = 0;
	g_gen.cycles_after_check = 0;
}

void		check_who_die(void)
{
	g_gen.check_in++;
	check_karetutu();
	if (CHECKSSS)
	{
		g_gen.cycles_to_die -= CYCLE_DELTA;
		g_gen.check_in = 0;
	}
	set_zero();
}
