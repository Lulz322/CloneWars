/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_sys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:49:39 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:49:40 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static struct s_lexeme		new_lexeme(struct s_lexeme lxm,
							enum e_kind kind, char smb)
{
	size_t					len;
	size_t					k;
	short					x;
	size_t					border;

	border = COMMENT_LENGTH + 1;
	x = 0;
	len = ft_strlen(lxm.string);
	lxm.kind = kind;
	if (len < border)
	{
		k = ft_strlen(lxm.string);
		lxm.string[k] = smb;
	}
	if (len == COMMENT_LENGTH + 5 || len == border)
	{
		x = error_mem_release();
		exit(x);
	}
	return (lxm);
}

static struct s_txt			lexeme_handle_mark(struct s_lexeme *lxm,
										struct s_txt smb, int file_index)
{
	short					mode;

	mode = 0;
	*lxm = new_lexeme(*lxm, Marker, smb.x);
	state_machine(&smb, file_index);
	while (ft_strrchr(LABEL_CHARS, smb.x))
	{
		*lxm = new_lexeme(*lxm, lxm->kind, smb.x);
		state_machine(&smb, file_index);
	}
	if (smb.x == LABEL_CHAR)
		;
	else
	{
		if (check_num_in_str(lxm->string, mode) == true)
			lxm->kind = Num;
		else if (check_reg(lxm->string, mode) == true)
			lxm->kind = Reg;
		else if (check_option(lxm->string, mode) == true)
			lxm->kind = Option;
	}
	return (smb);
}

static struct s_txt			handle_str(struct s_lexeme *lxm,
										struct s_txt smb, int file_index)
{
	struct s_txt			res;
	long					z;

	z = 0;
	lxm->kind = Str;
	state_machine(&smb, file_index);
	while (smb.x != 34)
	{
		if (!smb.x)
		{
			res.x = z;
			res.column = z;
			res.row = z;
			return (res);
		}
		*lxm = new_lexeme(*lxm, lxm->kind, smb.x);
		state_machine(&smb, file_index);
	}
	state_machine(&smb, file_index);
	return (smb);
}

static struct s_lexeme		lxm_filler(struct s_lexeme *lxm,
								struct s_txt smb)
{
	ft_bzero(lxm->string, COMMENT_LENGTH + 1);
	if (smb.x != -1)
		lxm->kind = -1;
	else
		lxm->kind = 0;
	lxm->column = smb.column;
	lxm->row = smb.row;
	return (*lxm);
}

struct s_lexeme				tokenizer(int file_index)
{
	struct s_lexeme			lxm;
	static struct s_txt		smb = {-1, -1, -1};

	if (smb.x == -1)
		state_machine(&smb, file_index);
	lxm = lxm_filler(&lxm, smb);
	if (ft_strrchr(SYMBOL_CHARS, smb.x))
	{
		lxm = new_lexeme(lxm, Symbol, smb.x);
		state_machine(&smb, file_index);
	}
	else if (is_cmt(smb.x) || spacing_check(smb.x) == true)
		smb = handle_whitespace(&lxm, smb, file_index);
	else if (ft_strrchr(LABEL_CHARS, smb.x))
		smb = lexeme_handle_mark(&lxm, smb, file_index);
	else if (smb.x == 34)
		smb = handle_str(&lxm, smb, file_index);
	return (lxm);
}
