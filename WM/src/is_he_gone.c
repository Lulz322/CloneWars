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

bool		is_die(t_kareta *kareta)
{
	return (g_gen.cycles_to_die <= 0
			|| g_gen.cycles - kareta->last_alive >= g_gen.cycles_to_die);
}

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

void		check_karetutu(t_kareta *prev)
{
	t_kareta *tmp;

	tmp = g_gen.kareta;
	while (tmp)
	{
		if (is_die(tmp))
			tmp = del(&tmp, prev);
		else
		{
			prev = tmp;
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
}

void		check_who_die(void)
{
	g_gen.check_in++;
	check_karetutu(NULL);
	IS_CYCLE;
	set_zero();
	ZERO;
}
