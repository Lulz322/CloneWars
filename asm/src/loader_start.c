/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:19 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/17 18:42:24 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void					load_codes_dataset(int num, long display,
						struct s_case *k, struct s_param param[3])
{
	int					p;
	short				z;

	p = k->k;
	z = 0;
	while (p <= 3)
	{
		num = num << 2;
		p = p + 1;
	}
	p = z;
	while (g_op_tab[k->code_set].octal)
	{
		display_static(display, &num, 1);
		load_markers(z)->ord_num = load_markers(z)->ord_num + 1;
		break ;
	}
	while (p < k->k)
	{
		display_static(display, &(param[p].val), param[p].sz);
		load_markers(z)->ord_num = load_markers(z)->ord_num + param[p].sz;
		p = p + 1;
	}
	load_markers(z)->ord_num = load_markers(z)->ord_num + 1;
}

short					load_code_set(long get, long display,
						struct s_lexeme *lxm, short code_set)
{
	struct s_case		k;
	int					num;
	struct s_param		p[3];

	num = 0;
	k.k = 0;
	k.code_set = code_set;
	*lxm = tokenizer(get);
	display_static(display, &(g_op_tab[code_set].code_set), 1);
	while (k.k < g_op_tab[code_set].nb_arg)
	{
		if (*(lxm->string) == SEPARATOR_CHAR && k.k && lxm->kind == Symbol)
			*lxm = tokenizer(get);
		else if (k.k != 0)
			return (-1);
		if ((p[k.k] = parse_arg(get, lxm, code_set)).sz == -1)
			return (-1);
		if (!(g_op_tab[code_set].args[k.k] & p[k.k].kind))
			return (-1);
		p[k.k].kind = (p[k.k].kind != T_IND) ? p[k.k].kind : IND_CODE;
		num = (num << 2) + p[k.k].kind;
		k.k = k.k + 1;
	}
	load_codes_dataset(num, display, &k, p);
	return (0);
}
