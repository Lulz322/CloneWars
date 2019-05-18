/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl_sys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:54:06 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:54:08 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_boolean		check_option(char *cmd, short int mode)
{
	short		k;
	short		z;
	size_t		l;

	z = 0;
	l = ft_strlen(cmd);
	k = z;
	while (mode == z && g_op_tab[k].name)
	{
		if (ft_strncmp(g_op_tab[k].name, cmd, l) == z)
		{
			return (true);
		}
		k++;
	}
	return (false);
}

short			take_option(char *cmds)
{
	short	k;
	short	z;
	size_t	l;

	z = 0;
	l = ft_strlen(cmds);
	k = z;
	while (g_op_tab[k].name)
	{
		while (ft_strncmp(g_op_tab[k].name, cmds, l) == z)
		{
			return (k);
		}
		k = k + 1;
	}
	return (--z);
}

t_boolean		check_num_in_str(char *txt, short int mode)
{
	void	*n;
	size_t	k;

	k = mode;
	n = NULL;
	if (txt == n)
	{
		return (false);
	}
	while (txt[k] != '\0' && !mode && ft_isdigit(txt[k]))
		k = k + 1;
	if (txt[k] != '\0' && !ft_isdigit(txt[k]))
		return (false);
	return (true);
}

t_boolean		check_reg(char *cmds, short int mode)
{
	size_t	j;
	int		flag;
	char	*rg;
	size_t	k;

	flag = mode;
	k = 3;
	rg = "r";
	j = 1;
	if (ft_strncmp(cmds, rg, j))
	{
		flag++;
	}
	else if (check_num_in_str(&(cmds[j]), mode) == false)
	{
		flag++;
	}
	else if (cmds[k] != '\0')
	{
		flag++;
	}
	if (flag != mode)
		return (false);
	else
		return (true);
}
