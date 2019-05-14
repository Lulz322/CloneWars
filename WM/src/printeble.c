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
	{
		ft_printf("* Player %d, weighing %d bytes,", a + 1, ST.champ[a].length);
		ft_printf("\"%-25.25s\" (\"%-25.25s\") !\n",
			ST.champ[a].name, ST.champ[a].comment);
	}
}

void	print_last_alive(void)
{
	if (ST.flag_visual)
		vs_announce_winner(2, 2, 0);
	else
		ft_printf("Player %d \"%s\" won!\n", ST.last_alive + 1,
			ST.champ[ST.last_alive].name);
	if (ST.flag_visual && ST.sounds)
	{
		kill_sounds();
		system("rm temp");
	}
}

void	print_dump(int a, int j)
{
	if (g_gen.v_field[a + j] == 1)
		ft_printf("{green}%.2x{eoc} ", g_gen.field[a + j]);
	else if (g_gen.v_field[a + j] == 2)
		ft_printf("{blue}%.2x{eoc} ", g_gen.field[a + j]);
	else if (g_gen.v_field[a + j] == 3)
		ft_printf("{cyan}%.2x{eoc} ", g_gen.field[a + j]);
	else if (g_gen.v_field[a + j] == 4)
		ft_printf("{yellow}%.2x{eoc} ", g_gen.field[a + j]);
	else
		ft_printf("%.2x ", g_gen.v_field[a + j]);
}

void	print_without_color(int i)
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
			ft_printf("%.2x ", g_gen.field[a + j]);
			j++;
		}
		ft_printf("\n");
		a+=i;
	}
}


void	print_field(int i)
{
	int a;
	int j;

	a = 0;
	print_without_color(i);
	exit(0);
	while (a < MEM_SIZE)
	{
		ft_printf("%.4p : ", a);
		j = 0;
		while (j < i)
		{
			if (karettta(a + j) == 1)
				ft_printf("{red}%.2x{eoc} ", g_gen.field[a + j]);
			else if (karettta(a + j) == 2)
				ft_printf("{yellow}%.2x{eoc} ", g_gen.field[a + j]);
			else if (karettta(a + j) == 3)
				ft_printf("{magenta}%.2x{eoc} ", g_gen.field[a + j]);
			else if (karettta(a + j) == 4)
				ft_printf("{cyan}%.2x{eoc} ", g_gen.field[a + j]);
			else
				print_dump(a, j);
			j++;
		}
		ft_printf("\n");
		a += i;
	}
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
			ft_printf("%02x ", g_gen.champ[a].algo[j]);
		ft_printf("\n\n\n");
	}
}
