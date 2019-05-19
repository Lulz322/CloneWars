/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:44:58 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 11:44:59 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_kareta	*create_elem(int pos)
{
	static	int	id;
	t_kareta	*elem;

	ERROR_MALLOC(elem = (t_kareta *)malloc(sizeof(t_kareta)));
	ft_bzero(elem, sizeof(t_kareta));
	elem->id = ++id;
	elem->reg[0] = -id;
	elem->pos = pos;
	g_gen.am_karet++;
	return (elem);
}

void		print_list(t_kareta *list)
{
	t_kareta *tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("[%d]    |   Position : %-4d\n", tmp->id, tmp->pos);
		tmp = tmp->next;
	}
}

void		add_elem(t_kareta **list, int pos)
{
	t_kareta *tmp;

	if (!*list)
		*list = create_elem(pos);
	else
	{
		tmp = create_elem(pos);
		tmp->next = *list;
		*list = tmp;
	}
}

t_kareta	*copy_kareta(t_kareta *kareta, int32_t addr)
{
	t_kareta	*new;
	int			i;

	new = create_elem(adress(kareta->pos + addr));
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = kareta->reg[i];
	new->carry = kareta->carry;
	new->last_alive = kareta->last_alive;
	jason_born();
	return (new);
}

void		next_op(t_kareta *kareta)
{
	kareta->pos = adress(kareta->pos + kareta->step);
	kareta->step = 0;
	ft_bzero(kareta->argc_types, 3);
}
