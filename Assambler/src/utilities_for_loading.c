/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_for_loading.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 03:55:35 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/14 03:55:40 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

short			skip_all_spaces(long get, struct s_lexeme *lxm)
{
	short		z;
	enum e_kind	tmp;

	z = 0;
	tmp = lxm->kind;
	while (check_sp_and_eol(tmp) < z)
	{
		*lxm = tokenizer(get);
		tmp = lxm->kind;
	}
	return (z);
}

long			handle_spaces(long get, struct s_lexeme *lxm)
{
	long		a;
	long		z;

	z = 0;
	a = 1;
	while (a != z)
	{
		a = z;
		if (lxm->kind == Space)
			a++;
		if (lxm->kind == Eol)
			a++;
		if (a != z)
			*lxm = tokenizer(get);
	}
	return (z);
}

short			read_handle_markers(long get, struct s_lexeme *lxm)
{
	short		res;
	short		z;

	z = 0;
	res = z;
	if ((*lxm = tokenizer(get)).kind != Symbol)
		res = 5;
	if (*(lxm->string) != LABEL_CHAR)
		res = 5;
	if (res == z)
		*lxm = tokenizer(get);
	return (res);
}
