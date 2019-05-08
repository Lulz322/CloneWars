/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_karetu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:49:29 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 12:49:30 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		make_step(t_kareta *kareta, t_operation *operation)
{
	int		i;
	int		step;

	i = -1;
	step = 0;
	step += 1 + (operation->args_types_code ? 1 : 0);
	while (++i < g_op[kareta->code - 1].args_num)
		step += count_step(kareta->argc_types[i], operation);
	return (step);
}

void	set_operation(t_kareta *kareta)
{
	_SET_OOP(kareta->code);
	if (_POOP)
		_CWAIT(kareta->wait);
}

void	do_func(t_kareta *kareta)
{
	t_operation	*new;

	new = NULL;
	if (_CHECK_WAIT)
		new = &g_op[kareta->code - 1];
	if (new)
	{
		read_argtype(kareta, new);
		if (validate_args(kareta, new) && check_args(kareta, new))
			new->func(kareta);
		else
			kareta->step += make_step(kareta, new);
	}
	else
		kareta->step = 1;
}

void	am_i_waiting(t_kareta *kareta)
{
	if (kareta->wait)
	{
		kareta->wait--;
		if (kareta->wait == 0)
			do_func(kareta);
	}
	else
		set_operation(kareta);
}

void	check_karetu(t_kareta *kareta)
{
	am_i_waiting(kareta);
	next_op(kareta);
}

void	run_cycle(void)
{
	t_kareta *tmp;

	_PREPARE(tmp);
	while (tmp)
	{
		check_karetu(tmp);
		tmp->living++;
		tmp = tmp->next;
	}
}

void	full_game(void)
{
	while (st.kareta)
	{
		_LOG(st.cycles + 1, st.cycles_after_check + 1);
		if (_RAVNO && (_FD || _FDUMP))
		{
			if (st.flag_visual)
			{
				_VS;
				timeout(-1);
				getch();
				endwin();
				exit(0);
			}
			else
				_PRINT_B;
		}
		if (!_FD && !_FDUMP)
			_VS;
		run_cycle();
		if (_AM_I_DIE)
			check_who_die();
		if (st.log == 2)
			ft_printf("Cycle to die is now %i\n", st.cycles_to_die);
	}
}

void	set_karetu(void)
{
	st.cycles_to_die = CYCLE_TO_DIE;
	print_info_champs();
	_CHECK_VISUALISATION;
	if (st.flag_visual && st.sounds)
		set_music();
	full_game();
}
