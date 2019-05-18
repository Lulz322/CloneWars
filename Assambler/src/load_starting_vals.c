/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_starting_vals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <dlenskyi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:50:12 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/05/07 00:50:14 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static short		check_kind(enum e_kind k)
{
	if (k == Marker)
		return (-1);
	if (k == Option)
		return (-2);
	if (k == No_mode)
		return (-3);
	return (0);
}

static short		handle_option(int get, int display,
										struct s_lexeme *lxm)
{
	short a;
	short res;

	a = take_option(lxm->string);
	res = 0;
	if (load_code_set(get, display, lxm, a))
		res = -1;
	while (check_sp_and_eol(lxm->kind) != -1 && !res)
	{
		if (check_sp_and_eol(lxm->kind) != -2)
			res = -1;
		if (!res)
			*lxm = tokenizer(get);
	}
	return (res);
}

static short		parse_data(long get, long display, struct s_lexeme *lxm)
{
	short x;

	x = check_kind(lxm->kind);
	skip_all_spaces(get, lxm);
	if (x < 0)
	{
		if (x == -1)
			read_handle_markers(get, lxm);
		if (x == -2)
			handle_option(get, display, lxm);
		if (x != -1 && x != -2 && x != -3)
			x = 12;
		else
			x = 0;
	}
	return (x);
}

short				run_assemble(char *get_name, char *display_name,
					struct s_flag *flg)
{
	struct s_lexeme	lexeme;
	struct s_load	t;

	t.res = 0;
	if (!get_name || !display_name || !ft_strcmp(get_name, display_name))
		exit(show_message(INPUT_ERR));
	if ((t.get = open(get_name, O_RDWR)) < 0)
		t.res = -1;
	if (create_marker_list(0, t.get, &t.amount, flg) && !t.res)
		t.res = -1;
	if (validate_starting_commands(t.get, &lexeme, flg) && !t.res)
		t.res = -1;
	if (!t.res)
	{
		if ((t.display = open(display_name, O_CREAT
			| O_RDWR, 0777)) < 0 && !t.res)
			t.res = -1;
		if (print_starting_commands(t.display, &t.amount, flg) && !t.res)
			t.res = -1;
		while (lexeme.kind != No_mode && !t.res)
			if (parse_data(t.get, t.display, &lexeme) && !t.res)
				t.res = 1;
	}
	return (t.res);
}
