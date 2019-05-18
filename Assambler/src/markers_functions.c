/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markers_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:49:08 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:49:18 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

struct s_ptr		*load_markers_work(int z)
{
	void					*n;
	static struct s_ptr		markers = (struct s_ptr){0, NULL};

	n = NULL;
	if (z == 0)
	{
		if (markers.mrk == n && !z)
		{
			markers.mrk = create_linked_nodes(n, 0);
			z++;
		}
	}
	else
		return (n);
	return (&markers);
}

long				marker_num(char *title)
{
	struct s_nodes				*markers;
	int							ord_num;
	int							z;
	long						res;
	int							x;

	z = 0;
	ord_num = z;
	res = -1;
	markers = load_markers(ord_num)->mrk;
	while (markers != NULL)
	{
		if (markers->object)
		{
			x = ft_strcmp(markers->object, title);
			if (x == z)
			{
				res = ord_num;
				break ;
			}
		}
		ord_num = ord_num + 1;
		markers = markers->after;
	}
	return (res);
}

long				marker_title(char *title, int ord_num)
{
	struct s_nodes	*markers;
	long			res;
	int				z;
	long			l;
	int				x;

	z = 0;
	x = z;
	res = 2147483647;
	markers = load_markers(z)->mrk;
	while (markers != NULL)
	{
		if (markers->object)
		{
			l = markers->sz_obj - ord_num;
			x = ft_strcmp(markers->object, title);
			if (x == z)
			{
				res = l;
				break ;
			}
		}
		markers = markers->after;
	}
	return (res);
}

short				pick_set_of_codes(long get, int *value,
							struct s_lexeme *lexeme, short code_set)
{
	int				i;
	int				j;
	struct s_param	param[3];

	i = -1;
	j = -1;
	*lexeme = tokenizer(get);
	*value += 1;
	while (++i < g_op_tab[code_set].nb_arg)
	{
		if (i && lexeme->kind == Symbol
		&& *(lexeme->string) == SEPARATOR_CHAR)
			*lexeme = tokenizer(get);
		else if (i)
			return (2);
		if ((param[i] = handle_args(get, lexeme, code_set)).sz == -1)
			return (1);
		if (!(g_op_tab[code_set].args[i] & param[i].kind))
			return (3);
	}
	if (g_op_tab[code_set].octal)
		*value += 1;
	while (++j < i)
		*value += param[j].sz;
	return (0);
}
