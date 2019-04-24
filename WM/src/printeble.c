/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printeble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:45:52 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 12:45:53 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_info_champs(void)
{
	int a;

	a = -1;
	ft_printf("Introducing contestants...\n");
	while (g_gen.champ[++a].length && a < 4)
		printf("* Player %d, weighing %d bytes, \"%-25.25s\" (\"%-25.25s\") !\n"
			, a + 1, st.champ[a].length, st.champ[a].name, st.champ[a].comment);
}

void	print_last_alive(void)
{
	ft_printf("Player %d \"%s\" won!\n", st.last_alive + 1,
		st.champ[st.last_alive].name);
	if (st.flag_visual)
	{
		kill_sounds();
		system("rm temp");
	}
}

void	print_field(int i)
{
	int a;
	int j;

	a = 0;
	while (a < MEM_SIZE)
	{
		ft_printf("%.4p : ", a);
		j = 0;
		while (j < i)
		{
			if (karettta(a + j) == 1)
				ft_printf("MRED(%.2x) ", g_gen.field[a + j]);
			else if (karettta(a + j) == 2)
				ft_printf("MYLW(%.2x) ", g_gen.field[a + j]);
			else if (karettta(a + j) == 3)
				ft_printf("MPRP(%.2x) ", g_gen.field[a + j]);
			else if (karettta(a + j) == 4)
				ft_printf("MCYN(%.2x) ", g_gen.field[a + j]);
			else
			{
				if (g_gen.v_field[a + j] == 1)
					ft_printf("MGRN(%.2x) ", g_gen.field[a + j]);
				else if (g_gen.v_field[a + j] == 2)
					ft_printf("MBLU(%.2x) ", g_gen.field[a + j]);
				else if (g_gen.v_field[a + j] == 3)
					ft_printf("MCYN(%.2x) ", g_gen.field[a + j]);
				else if (g_gen.v_field[a + j] == 4)
					ft_printf("MYLW(%.2x) ", g_gen.field[a + j]);
				else
					ft_printf("%.2x ", g_gen.v_field[a + j]);
			}
			j++;
		}
		ft_printf("\n");
		a += i;
	}
}

void	logs(int i, int d)
{
	ft_printf("It is now cycle %llu, after check %i\n", i, d);
}

void	print_player_code(void)
{
	int a;
	int j;

	a = -1;
	while (++a < 4 && g_gen.champ[a].name)
	{
		j = -1;
		while (++j < g_gen.champ[a].length)
			printf("%02x ", g_gen.champ[a].algo[j]);
		printf("\n\n\n");
	}
}
