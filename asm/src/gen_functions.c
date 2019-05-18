/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 02:52:13 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/14 02:52:19 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

short			check_sp_and_eol(enum e_kind k)
{
	short int res;

	res = 0;
	if (k == Eol)
	{
		res = -1;
		return (res);
	}
	else if (k == Space)
	{
		res = -2;
		return (res);
	}
	return (res);
}

long			provide_source(char *object, int mode)
{
	int result;
	int ch_mod;

	ch_mod = 0777;
	result = 0;
	if (mode == 1)
	{
		result = open(object, O_RDWR);
		return (result);
	}
	else
	{
		result = open(object, O_CREAT | O_RDWR, ch_mod);
		return (result);
	}
}

struct s_nodes	*create_linked_nodes(void *obj_src, size_t sz_src)
{
	struct s_nodes	*fresh_nodes;
	void			*n;

	n = NULL;
	fresh_nodes = (struct s_nodes*)malloc(sizeof(struct s_nodes));
	if (!fresh_nodes)
		return (n);
	if (obj_src)
	{
		fresh_nodes->object = malloc(sz_src);
		if (fresh_nodes->object == n)
		{
			free(fresh_nodes);
			return (n);
		}
		ft_memcpy(fresh_nodes->object, obj_src, sz_src);
		fresh_nodes->sz_obj = sz_src;
	}
	else if (obj_src == n)
	{
		fresh_nodes->object = n;
		fresh_nodes->sz_obj = 0;
	}
	fresh_nodes->after = n;
	return (fresh_nodes);
}

short int		show_details(char *txt)
{
	short	stream;

	stream = 2;
	write(stream, txt, ft_strlen(txt));
	return (0);
}

short int		add_node_end(struct s_nodes **start_list,
							struct s_nodes *moded_list)
{
	int				z;
	struct s_nodes	*tech;
	void			*n;

	z = 0;
	n = NULL;
	tech = *start_list;
	if (*start_list == n && moded_list != n)
	{
		*start_list = moded_list;
		moded_list->after = n;
		return (z);
	}
	else if (*start_list != n && moded_list != n)
	{
		while (tech->after != n)
			tech = tech->after;
		tech->after = moded_list;
		moded_list->after = n;
	}
	else
		return (--z);
	return (z);
}
