/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markers_starter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:48:51 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:48:53 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			show_mistake_info(char *msg)
{
	size_t	l;
	size_t	i;
	size_t	b;
	size_t	a;
	char	x;

	x = ':';
	a = 15;
	write(2, UMRK_ERR, a);
	l = ft_strlen(msg);
	write(2, msg, l);
	b = 29;
	write(2, UMRK_ERR_2, b);
	i = 1;
	write(2, &x, i);
	write(2, msg, l);
	x = '\"';
	write(2, &x, i);
	EOL;
}

short				if_safe_marker(short a)
{
	struct s_nodes	*mks;
	void			*n;
	short int		z;

	z = 0;
	n = NULL;
	mks = load_markers_work(z)->mrk;
	if (a == z)
	{
		while (mks != n && !z)
		{
			if (mks->object)
			{
				while (marker_num(mks->object) == a)
				{
					show_mistake_info(mks->object);
					return (a);
				}
			}
			mks = mks->after;
		}
	}
	return (z);
}

short				handle_marker(long get,
								struct s_lexeme *lxm, const int *amount)
{
	short i;

	i = 0;
	if (place_marker(lxm->string, *amount))
		i = 1;
	if (((*lxm = tokenizer(get)).kind != Symbol ||
					*(lxm->string) != LABEL_CHAR) && !i)
		i = 2;
	*lxm = tokenizer(get);
	return (i);
}

short				handle_code_set(long get,
									struct s_lexeme *lxm, int *amount)
{
	short		i;
	short int	k;

	i = take_option(lxm->string);
	k = pick_set_of_codes(get, amount, lxm, i);
	i = 0;
	if (k != i)
	{
		i++;
	}
	while (!i && lxm->kind != Eol && !k)
	{
		if (lxm->kind != Space)
		{
			i = 2;
			k++;
			break ;
		}
		*lxm = tokenizer(get);
	}
	return (i);
}

short				create_marker_list(short m_code, long get,
							int *amount, struct s_flag *flg)
{
	struct s_lexeme			lxm;

	*amount = m_code;
	m_code = (validate_name_cmt(get, &lxm, flg) != 0) ? 1 : 0;
	if (get)
		while (lxm.kind != No_mode && !m_code)
		{
			handle_spaces(get, &lxm);
			if (lxm.kind == Marker)
			{
				if (handle_marker(get, &lxm, amount))
					m_code = -1;
			}
			else if (lxm.kind == Option)
			{
				if (handle_code_set(get, &lxm, amount))
					m_code = -1;
			}
			else if (lxm.kind != No_mode)
				m_code = -1;
		}
	if (if_safe_marker(-1) && !m_code)
		m_code = -1;
	m_code != 0 ? lang_mistake(lxm) : lseek(get, 0, SEEK_SET);
	return (m_code);
}
