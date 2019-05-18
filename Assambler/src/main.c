/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:46:55 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:47:00 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static short		display(char *result)
{
	short			s;
	char			*txt;

	txt = RES;
	s = 1;
	if (result)
	{
		write(s, txt, ft_strlen(txt));
		write(s, result, ft_strlen(result));
		write(s, "\n", s);
	}
	return (s);
}

short				show_message(char *txt)
{
	short			s;

	s = 2;
	write(s, txt, ft_strlen(txt));
	return (1);
}

static void			is_safe_args(int ac, char **av, struct s_flag *flg, int *i)
{
	if (!ft_strcmp(av[*i], "--reverse") || !ft_strcmp(av[*i], "-R"))
	{
		if (ac != 2)
			flg->dsm = 1;
		else
			exit(show_message(USAGE));
	}
	if (!ft_strcmp(av[*i], "--original") || !ft_strcmp(av[*i], "-O"))
	{
		if (ac > 2)
			flg->orig = 1;
		else
			exit(show_message(USAGE));
	}
	if (!ft_strcmp(av[*i], "--help"))
		exit(show_message("USAGE:\n\n ./asm [-O] -R champion.cor | \
[-O] champion.s \
\n\n-O --original  ASM can obtain multiple files, but will use only last one. \
\n-R --reverse  ASM will make file opposite of assembling, \
use only for .cor files.\n--help  Output this help.\n"));
}

static void			parse_args(int ac, char **av, struct s_flag *flg)
{
	int				i;

	i = 1;
	if (ac < 2)
		exit(show_message(USAGE));
	while (av[i])
	{
		is_safe_args(ac, av, flg, &i);
		i++;
	}
}

int					main(int ac, char **av)
{
	struct s_hold	a;
	struct s_flag	flg;

	ft_bzero(&flg, sizeof(flg));
	parse_args(ac, av, &flg);
	if ((!flg.orig && flg.dsm && ac > 3) || (!flg.orig && !flg.dsm && ac > 2))
		exit(show_message(USAGE));
	if (flg.dsm)
	{
		if (!(a.result = validate_arg_title(flg.orig ? av[ac - 1] : av[2], 4)))
			exit(show_message(USAGE));
		if (make_recoding((flg.orig) ? av[ac - 1] : av[2], a.result) < 0)
			exit(mem_release(NULL, &flg));
	}
	else
	{
		if (!(a.result = validate_arg_title(flg.orig ? av[ac - 1] : av[1], 2)))
			exit(show_message(RD_ERR));
		if (run_assemble((flg.orig) ? av[ac - 1] : av[1], a.result, &flg) != 0)
			exit(mem_release(ST_CMD_ERR, &flg));
	}
	display(a.result);
	free(a.result);
	mem_release(NULL, &flg);
	return (0);
}
