/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 04:45:17 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/17 04:45:20 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_boolean					spacing_check(char x)
{
	char					*sp;

	sp = " \r\n\v\f\t";
	if (ft_strrchr(sp, x))
		return (true);
	return (false);
}

short						is_cmt(char x)
{
	short					res;

	res = 0;
	if (x == COMMENT_CHAR)
		res++;
	if (x == ALT_COMMENT_CHAR && !res)
		res++;
	return (res);
}

static struct s_txt			txt_filler(void)
{
	struct s_txt			res;
	int						z;

	z = 0;
	res.x = z;
	res.column = z;
	res.row = z;
	return (res);
}

static struct s_txt			skip_cmt(struct s_lexeme *lxm,
							struct s_txt *smb, const int *file_index)
{
	while (is_cmt(smb->x))
	{
		lxm->kind = Cmt;
		while (smb->x != '\n')
		{
			if (!smb->x)
				return (txt_filler());
			if (smb->x == '\xff')
				exit(lang_mistake(*lxm));
			state_machine(smb, *file_index);
		}
	}
	return (*smb);
}

struct s_txt				handle_whitespace(struct s_lexeme *lxm,
							struct s_txt smb, int file_index)
{
	while (spacing_check(smb.x) == true || is_cmt(smb.x))
	{
		while (spacing_check(smb.x) == true)
		{
			lxm->kind = Space;
			while (spacing_check(smb.x) == true)
			{
				if (smb.x == '\n')
					lxm->kind = Eol;
				state_machine(&smb, file_index);
			}
		}
		smb = skip_cmt(lxm, &smb, &file_index);
	}
	return (smb);
}
