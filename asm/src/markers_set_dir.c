/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markers_set_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 04:40:37 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/17 04:40:40 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long				find_param_sz(t_op g_op_tab)
{
	long			size;

	if (!g_op_tab.marker)
		size = DIR_SIZE;
	else
		size = DIR_SIZE / 2;
	return (size);
}

static void			load_marker_smb_dir(struct s_lexeme *lxm, long get,
					struct s_param *param, short code_set)
{
	struct s_nodes	*a;
	size_t			l;
	struct s_nodes	*s;
	short			z;

	*lxm = tokenizer(get);
	z = 0;
	param->kind = T_DIR;
	param->val = z;
	param->sz = find_param_sz(g_op_tab[code_set]);
	l = 1 + ft_strlen(lxm->string);
	s = load_markers_work(z)->mrk;
	a = create_linked_nodes(lxm->string, l);
	add_node_end(&s, a);
}

static void			handle_neg_pos(long get, struct s_lexeme *lexeme,
					short code_set, struct s_param *param)
{
	short			neg_pos;

	find_neg_pos(&neg_pos, lexeme);
	*lexeme = tokenizer(get);
	if (lexeme->kind == Num)
	{
		param->kind = T_DIR;
		param->val = ft_atoi(lexeme->string) * neg_pos;
		param->sz = find_param_sz(g_op_tab[code_set]);
	}
}

struct s_param		param_dir_picking(long get, struct s_lexeme *lexeme,
					short code_set, struct s_param param)
{
	char			pl;
	char			mn;

	pl = 43;
	mn = 45;
	*lexeme = tokenizer(get);
	if (lexeme->kind == Num)
		param = (struct s_param){T_DIR, ft_atoi(lexeme->string),
			(g_op_tab[code_set].marker) ? DIR_SIZE / 2 : DIR_SIZE};
	if (lexeme->kind == Symbol)
	{
		if (*(lexeme->string) == mn || *(lexeme->string) == pl)
			handle_neg_pos(get, lexeme, code_set, &param);
		else if (*(lexeme->string) == LABEL_CHAR)
			load_marker_smb_dir(lexeme, get, &param, code_set);
	}
	return (param);
}
