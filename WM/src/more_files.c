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

	tmp = g_gen.kareta;
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
	if (mode == 2 && g_gen.log == 2)
		ft_printf("Cycle to die is now %i\n", g_gen.cycles_to_die);
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

void		print_info_champs(void)
{
	int a;

	a = -1;
	ft_printf("Introducing contestants...\n");
	while (g_gen.champ[++a].length && a < 4)
	{
		ft_printf("* Player %d, weighing %d bytes, ",
			a + 1, g_gen.champ[a].length);
		ft_printf("\"%s\" (\"%s\") !\n",
			g_gen.champ[a].name, g_gen.champ[a].comment);
	}
}
