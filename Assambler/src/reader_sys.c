/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_sys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:47:32 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:47:34 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						lang_mistake(struct s_lexeme lxm)
{
	char				*txt1;
	size_t				i;
	int					x;
	char				c;

	i = 1;
	txt1 = LANG_ERR;
	write(2, txt1, ft_strlen(txt1));
	x = lxm.row;
	ft_putnbr_fd(x, 2);
	c = 58;
	write(2, &c, i);
	x = lxm.column;
	ft_putnbr_fd(x, 2);
	c = 41;
	write(2, &c, i);
	EOL;
	return (0);
}

static struct s_txt		txt_loader(int y, char n, int x)
{
	struct s_txt		a;

	a.row = y;
	a.x = n;
	a.column = x;
	return (a);
}

void					state_machine(struct s_txt *smb, int fd)
{
	static int			x = 0;
	static int			y = 1;
	char				n;
	ssize_t				i;

	x++;
	i = read(fd, &n, 1);
	if (i >= 1)
	{
		if (n == 10)
		{
			x = 0;
			y++;
		}
		*smb = txt_loader(y, n, x);
	}
	if (i < 1)
	{
		n = -1;
		*smb = txt_loader(y, n, x);
		if (smb->x == '\xff')
			return ;
	}
}
