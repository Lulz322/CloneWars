/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markers_set_indir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 04:40:48 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/17 04:40:50 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

short				find_neg_pos(short *neg_pos, struct s_lexeme *l)
{
	if (*(l->string) == 45)
		*neg_pos = -1;
	else
		*neg_pos = 1;
	return (*neg_pos);
}

static void			load_lab_chr_indir(struct s_lexeme *lxm, long get,
					struct s_param *param)
{
	struct s_nodes	*a;
	size_t			l;
	struct s_nodes	*s;
	short			z;

	*lxm = tokenizer(get);
	z = 0;
	param->kind = T_IND;
	param->val = z;
	param->sz = IND_SIZE;
	l = 1 + ft_strlen(lxm->string);
	s = load_markers_work(z)->mrk;
	a = create_linked_nodes(lxm->string, l);
	add_node_end(&s, a);
}

struct s_param		param_indir_picking(long get, struct s_lexeme *lxm,
					struct s_param param)
{
	char			pl;
	short			neg_pos;
	char			mn;

	pl = 43;
	mn = 45;
	if (*(lxm->string) == mn || *(lxm->string) == pl)
	{
		find_neg_pos(&neg_pos, lxm);
		*lxm = tokenizer(get);
		if (lxm->kind == Num)
		{
			param.kind = T_IND;
			param.val = ft_atoi(lxm->string) * neg_pos;
			param.sz = IND_SIZE;
		}
	}
	if (*(lxm->string) == LABEL_CHAR)
		load_lab_chr_indir(lxm, get, &param);
	return (param);
}
