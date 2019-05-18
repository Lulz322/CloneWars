/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 03:23:26 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/14 03:23:30 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static short		erase_ptr(void *object, size_t len)
{
	size_t	z;
	void	*n;

	z = 0;
	n = NULL;
	if (object != n)
	{
		free(object);
		object = n;
	}
	len = z;
	return (z);
}

void				show_mistake(char *msg)
{
	size_t	k;
	size_t	l;
	int		stream;

	l = ft_strlen(msg);
	stream = 2;
	k = 0;
	while (k < l)
	{
		write(stream, &msg[k], 1);
		k++;
	}
	EOL;
}

static short		nodes_eraser(struct s_nodes **nodes,
								short (*del)(void *, size_t))
{
	struct s_nodes	*tech;
	void			*n;

	n = NULL;
	if (*nodes && del)
	{
		while (*nodes != n)
		{
			del((*nodes)->object, (*nodes)->sz_obj);
			tech = *nodes;
			(*nodes) = (*nodes)->after;
			free(tech);
			tech = n;
		}
	}
	else if (*nodes == n)
	{
		return (1);
	}
	return (0);
}

short				error_mem_release(void)
{
	char			*txt;
	struct s_nodes	**l;
	struct s_nodes	**n;

	txt = QUOTE_ERR;
	l = &(load_markers(0)->mrk);
	nodes_eraser(l, &erase_ptr);
	n = &(load_markers_work(0)->mrk);
	nodes_eraser(n, &erase_ptr);
	show_mistake(txt);
	return (1);
}

short				mem_release(const char *s, struct s_flag *flg)
{
	short			z;
	struct s_nodes	**l;
	struct s_nodes	**n;

	z = 0;
	l = &(load_markers(z)->mrk);
	nodes_eraser(l, &erase_ptr);
	n = &(load_markers_work(z)->mrk);
	nodes_eraser(n, &erase_ptr);
	if (s)
	{
		if (ft_strlen(flg->cmt_tmp) > COMMENT_LENGTH)
			return (show_cmt_name_limit(COMMENT_LENGTH));
		else if (ft_strlen(flg->name_tmp) > PROG_NAME_LENGTH)
			return (show_cmt_name_limit(PROG_NAME_LENGTH));
		else if (s == RD_ERR)
			show_mistake(RD_ERR);
		return (1);
	}
	return (z);
}
