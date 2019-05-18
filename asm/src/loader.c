/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:50:21 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:50:29 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			arg_filler(char kind, long res, long sz,
					struct s_param *param)
{
	param->kind = kind;
	param->val = res;
	param->sz = sz;
}

struct s_param		load_param_indir(long get, struct s_lexeme *lxm,
					struct s_param param)
{
	t_np			s;
	short			neg_pos;
	short			z;

	z = 0;
	s.pl = 43;
	s.mn = 45;
	if (*(lxm->string) == LABEL_CHAR)
	{
		*lxm = tokenizer(get);
		if (marker_num(lxm->string) != -1)
			arg_filler(T_IND, marker_title(lxm->string,
				load_markers(z)->ord_num), IND_SIZE, &param);
	}
	else if (*(lxm->string) == s.mn || *(lxm->string) == s.pl)
	{
		find_neg_pos(&neg_pos, lxm);
		*lxm = tokenizer(get);
		if (lxm->kind == Num)
			arg_filler(T_IND, neg_pos * ft_atoi(lxm->string),
				IND_SIZE, &param);
	}
	return (param);
}

static void			filler_dir_param(struct s_param *param,
					short code_set, long res)
{
	param->kind = T_DIR;
	param->val = res;
	param->sz = find_param_sz(g_op_tab[code_set]);
}

struct s_param		load_param_dir(long get, struct s_lexeme *lxm,
					short code_set, struct s_param p)
{
	short			neg_pos;

	*lxm = tokenizer(get);
	if (lxm->kind == Num)
		filler_dir_param(&p, code_set, ft_atoi(lxm->string));
	else if (lxm->kind == Symbol)
	{
		if (*(lxm->string) == 45 || *(lxm->string) == 43)
		{
			find_neg_pos(&neg_pos, lxm);
			*lxm = tokenizer(get);
			if (lxm->kind == Num)
				filler_dir_param(&p, code_set, neg_pos * ft_atoi(lxm->string));
		}
		else if (*(lxm->string) == LABEL_CHAR)
		{
			*lxm = tokenizer(get);
			if (marker_num(lxm->string) != -1)
				filler_dir_param(&p, code_set,
					marker_title(lxm->string, load_markers(0)->ord_num));
		}
	}
	return (p);
}

struct s_param		parse_arg(long get, struct s_lexeme *lxm, short code_set)
{
	struct s_param	param;
	long			x;

	x = -1;
	arg_filler(x, x, x, &param);
	while (lxm->kind == Space)
	{
		*lxm = tokenizer(get);
	}
	if (lxm->kind == Num)
		arg_filler(T_IND, ft_atoi(lxm->string), IND_SIZE, &param);
	else if (lxm->kind == Symbol)
	{
		if (*(lxm->string) == DIRECT_CHAR)
			param = load_param_dir(get, lxm, code_set, param);
		else
			param = load_param_indir(get, lxm, param);
	}
	else if (lxm->kind == Reg)
		arg_filler(T_REG, ft_atoi(lxm->string + 1), 1, &param);
	while ((*lxm = tokenizer(get)).kind == Space)
		;
	return (param);
}
