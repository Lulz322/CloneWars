/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:49:23 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:49:25 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int				start_cmds_util(long get, struct s_lexeme *lexeme,
						struct s_flag *flg, int *z)
{
	struct s_lbs		a;
	int					res;

	a.cmd_nm = "name";
	a.cmd_cm = "comment";
	res = 0;
	*lexeme = tokenizer(get);
	while (lexeme->kind == Space || lexeme->kind == Eol)
		*lexeme = tokenizer(get);
	if (lexeme->kind != Symbol || *(lexeme->string) != '.')
	{
		res = -1;
		return (res);
	}
	*lexeme = tokenizer(get);
	if (!flg->flag)
	{
		check_name_cmt(flg, lexeme);
		flg->flag = 1;
	}
	if (lexeme->kind != Marker || ft_strncmp(lexeme->string, a.cmd_nm, 5))
		*z += 1;
	else if (lexeme->kind != Marker || ft_strncmp(lexeme->string, a.cmd_cm, 8))
		*z += 1;
	return (res);
}

static short			arg_filler(struct s_param *param,
						char x, char *s, long amount)
{
	param->kind = x;
	param->val = ft_atoi(s);
	param->sz = amount;
	return (param->val);
}

static short			process_smb(long get, int code_set,
						struct s_lexeme *lxm, struct s_param *param)
{
	short				z;

	z = 0;
	if (*(lxm->string) != DIRECT_CHAR)
		*param = param_indir_picking(get, lxm, *param);
	else
		*param = param_dir_picking(get, lxm, code_set, *param);
	return (z);
}

struct s_param			handle_args(long get, struct s_lexeme *lxm,
						short code_set)
{
	struct s_param		param;
	short				i;
	short				x;

	x = -1;
	i = 1;
	param.kind = x;
	param.val = x;
	param.sz = x;
	while (lxm->kind == Space)
		*lxm = tokenizer(get);
	if (lxm->kind == Num)
		arg_filler(&param, T_IND, lxm->string, IND_SIZE);
	if (lxm->kind == Reg)
		arg_filler(&param, T_REG, lxm->string, i);
	if (lxm->kind == Symbol)
		process_smb(get, code_set, lxm, &param);
	while (i || lxm->kind == Space)
	{
		i--;
		*lxm = tokenizer(get);
	}
	return (param);
}

short					validate_name_cmt(long get, struct s_lexeme *lexeme,
									struct s_flag *flg)
{
	size_t				k;
	int					z;
	short				res;

	k = -1;
	while (++k <= 1)
	{
		z = 0;
		res = start_cmds_util(get, lexeme, flg, &z);
		if (z == 2)
			return (-1);
		while ((*lexeme = tokenizer(get)).kind == Space)
			;
		if (lexeme->kind != Str)
			return (-1);
		while ((*lexeme = tokenizer(get)).kind != Eol)
			if (lexeme->kind != Space)
				return (-1);
	}
	return (res);
}
