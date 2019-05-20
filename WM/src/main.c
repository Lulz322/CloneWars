/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:47:59 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 11:48:00 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			errrorrororo(void)
{
	ft_printf("{green}Usage: ./corewar [-d N] [-dump N] [-a] [-l N] [-v]{eoc}");
	ft_printf(" {green}[-s] [-n N{1 - 4}] {champ_name.cor , ...}\n");
	ft_printf("\t{red}-d\t{red}Print Battlefield in 64 octets in a row\n");
	ft_printf("\t{red}-dump\t{blue}Print Battlefield in 32 octets in row\n");
	ft_printf("\t{red}-a\tRly I don't know how it's working\n");
	ft_printf("\t{red}-l\t{cyan}Verbosity levels\n");
	ft_printf("\t{red}-v\t{yellow}Turn on a Visualisation\n");
	ft_printf("\t{red}-s\t{yellow}Turn on a Sounds\n");
	ft_printf("\t{red}-n\t{magenta}Set player Number  N\n");
	ft_printf("\t\t%-10s- speed\n\t\t%-11s - pause\n", " <- || ->", "Space");
	ft_printf("\t\t%-11s - Quit\n", "q");
	exit(0);
}

int				main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	parsing_argc(argc, argv);
	ERR_CHAMP(g_gen.champ[0].length);
	create_field();
	set_karetu();
	print_last_alive();
}
