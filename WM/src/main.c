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
	ft_printf("MGRN(Usage: ./corewar [-d N] [-dump N] [-a] [-l N] [-v] ");
	ft_printf("MGRN([-n N{1 - 4}] {champ_name.cor , ...})\n");
	ft_printf("\tMRED(-d)\tMRED(Print Battlefield in 64 octets in a row)\n");
	ft_printf("\tMRED(-dump)\tMBLU(Print Battlefield in 32 octets in row)\n");
	ft_printf("\tMRED(-a)\tRly I don't know how it's working\n");
	ft_printf("\tMRED(-l)\tMCYN(Verbosity levels)\n");
	ft_printf("\tMRED(-n)\tMPRP(Set player Number  N)\n");
	ft_printf("\tMRED(-v)\tMYLW(Turn on a Visualisation\n");
	ft_printf("\t\t%-10s- speed\n\t\t%-11s - pause\n", " <- || ->", "Space");
	ft_printf("\t\t%-11s - Quit\n", "q");
	exit(0);
}

int				main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	parsing_argc(argc, argv);
	_ERR_CHAMP(g_gen.champ[0].length);
	create_field();
	printf("%d\n", st.flag_visual);//remove printf
	set_karetu();
	print_last_alive();
	//system("leaks corewar");
}
