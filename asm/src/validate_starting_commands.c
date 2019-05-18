/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_starting_commands.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 12:16:19 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/05/16 12:16:21 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

short		show_cmt_name_limit(int x)
{
	short s;
	short result;

	s = 2;
	result = 4;
	if (x == COMMENT_LENGTH)
		write(s, CMT_ERR, ft_strlen(CMT_ERR));
	else if (x == PROG_NAME_LENGTH)
		write(s, NAME_ERR, ft_strlen(NAME_ERR));
	ft_putnbr_fd(x, s);
	EOL;
	return (result);
}

void		check_name_cmt(struct s_flag *flg, struct s_lexeme *lexeme)
{
	char *cmd_nm;
	char *cmd_cm;

	cmd_nm = "name";
	cmd_cm = "comment";
	if (!ft_strncmp(lexeme->string, cmd_nm, 5))
		flg->name = 1;
	else if (!ft_strncmp(lexeme->string, cmd_cm, 8))
		flg->cmt = 1;
}

void		copy_name_str(struct s_flag *flg, char *s)
{
	if (flg->cmt)
	{
		ft_strcpy(flg->cmt_tmp, s);
		flg->cmt = 0;
		flg->name = 1;
	}
	else if (flg->name)
	{
		ft_strcpy(flg->name_tmp, s);
		flg->cmt = 1;
		flg->name = 0;
	}
}

short		load_starting_commands(long get, struct s_lexeme *lxm,
			struct s_flag *flg)
{
	int				k;
	struct s_lbs	l;
	short			z;

	z = 0;
	l.result = 0;
	l.cmd_nm = "name";
	l.cmd_cm = "comment";
	*lxm = tokenizer(get);
	while (lxm->kind == Space || lxm->kind == Eol)
		*lxm = tokenizer(get);
	if (lxm->kind != Symbol || *(lxm->string) != '.')
		z = 1;
	*lxm = tokenizer(get);
	if (flg->name && !z)
		k = ft_strncmp(lxm->string, l.cmd_nm, 5);
	else if (flg->cmt && !z)
		k = ft_strncmp(lxm->string, l.cmd_cm, 8);
	if ((lxm->kind != Marker || k != 0) && !z)
		z = 2;
	if (z != 0)
		l.result = z;
	return (l.result);
}

short		validate_starting_commands(long get,
			struct s_lexeme *lxm, struct s_flag *flg)
{
	struct s_hold	a;

	a.res = 0;
	a.k = 0;
	while (a.k <= 1)
	{
		if (load_starting_commands(get, lxm, flg) && !a.res)
			a.res = 1;
		while ((*lxm = tokenizer(get)).kind == Space && !a.res)
			a.res = 0;
		copy_name_str(flg, lxm->string);
		if (lxm->kind != Str && !a.res)
			a.res = 3;
		if (ft_strlen(flg->name_tmp) > PROG_NAME_LENGTH && !a.res)
			a.res = 4;
		if (ft_strlen(flg->cmt_tmp) > COMMENT_LENGTH && !a.res)
			a.res = 4;
		while ((*lxm = tokenizer(get)).kind != Eol && !a.res)
			if (lxm->kind != Space)
				a.res = 4;
		a.k = a.k + 1;
	}
	return (a.res);
}
