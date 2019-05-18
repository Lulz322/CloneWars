/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_entering_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <dlenskyi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:49:57 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/05/07 00:49:59 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			make_some_magic(long display)
{
	unsigned int	z;
	unsigned int	num;

	z = 0;
	num = COREWAR_EXEC_MAGIC;
	display_static(display, &num, sizeof(num));
	return (z);
}

static void			start_cmds_display(int *amount, long fd,
					struct s_flag *flg, unsigned int k)
{
	size_t			len;

	len = 4 + PROG_NAME_LENGTH;
	write(fd, flg->name_tmp, len);
	display_static(fd, amount, sizeof(k));
	len = 4 + COMMENT_LENGTH;
	write(fd, flg->cmt_tmp, len);
}

short				print_starting_commands(long display, int *amount,
					struct s_flag *flg)
{
	unsigned int	k;

	k = 1;
	make_some_magic(display);
	start_cmds_display(amount, display, flg, k);
	return (0);
}
