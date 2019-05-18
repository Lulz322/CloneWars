/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:51:10 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/16 14:51:13 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static long		markers_filler(struct s_nodes *new_markers,
				struct s_nodes *markers, int ident)
{
	long	z;

	z = 0;
	new_markers->sz_obj = ident;
	markers = load_markers(z)->mrk;
	add_node_end(&markers, new_markers);
	return (z);
}

long			place_marker(char *title, int ident)
{
	struct s_nodes		*new_markers;
	struct s_nodes		*markers;
	size_t				l;
	long				res;

	l = 0;
	markers = NULL;
	new_markers = NULL;
	res = 0;
	if (title == NULL)
		new_markers = create_linked_nodes(NULL, 0);
	else
	{
		l = ft_strlen(title);
		if (marker_num(title) != -1)
			res = 1;
		if (!res)
			new_markers = create_linked_nodes(title, l);
	}
	if (!res)
		markers_filler(new_markers, markers, ident);
	return (res);
}

size_t			make_backwards_2(unsigned int x)
{
	size_t		done;
	size_t		dir_bwd;

	done = 0x000000FF;
	dir_bwd = x & done;
	BWD_REV + ((0x0000FF00 & x) >> 8);
	BWD_REV + ((0x00FF0000 & x) >> 16);
	BWD_REV + ((0xFF000000 & x) >> 24);
	done = dir_bwd;
	return (done);
}

size_t			make_backwards_1(unsigned int x)
{
	size_t		dir_bwd;
	size_t		done;

	done = 0xFF;
	dir_bwd = x & done;
	BWD_REV + ((0xFF00 & x) >> 8);
	done = dir_bwd;
	return (done);
}

struct s_ptr	*load_markers(int z)
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
