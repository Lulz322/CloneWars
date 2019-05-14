/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:52:52 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:52:53 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

bool		is_dat_is_a_child(int i)
{
	t_kareta *tmp;

	tmp = ST.kareta;
	while (tmp)
	{
		if (tmp->pos == i && tmp->living <= 50)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void		logs(int i, int d, int mode)
{
	if (mode == 1)
		ft_printf("It is now cycle %llu, after check %i\n", i, d);
	if (mode == 2 && ST.log == 2)
		ft_printf("Cycle to die is now %i\n", ST.cycles_to_die);
}

int			g_farewell(t_kareta *kareta, t_operation *operation)
{
	int		i;
	int		step;

	i = -1;
	step = 0;
	step += 1 + (operation->args_types_code ? 1 : 0);
	while (++i < g_op[kareta->code - 1].args_num)
		step += how_m_steps(kareta->argc_types[i], operation);
	return (step);
}

void		set_operation(t_kareta *kareta)
{
	SET_OOP(kareta->code);
	if (POOP)
		CWAIT(kareta->wait);
}

void		do_func(t_kareta *kareta)
{
	t_operation	*new;

	new = NULL;
	if (CHECK_WAIT)
		new = &g_op[kareta->code - 1];
	if (new)
	{
		r_arg(kareta, new);
		if (val_argc(kareta, new) && check_args(kareta, new))
			new->func(kareta);
		else
			kareta->step += g_farewell(kareta, new);
	}
	else
		kareta->step = 1;
}
