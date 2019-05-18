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

#define FOR_CHECK 1

void	print_last_alive(void)
{
	if (g_gen.flag_visual)
		vs_announce_winner(2, 2, 0);
	else
		ft_printf("Player %d \"%s\" won!\n", g_gen.last_alive + 1,
			g_gen.champ[g_gen.last_alive].name);
	if (g_gen.flag_visual && g_gen.sounds)
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
		a += i;
	}
	exit(0);
}

void	gavno(void)
{
	int i;

	if (g_gen.flag_d)
		i = 64;
	else
		i = 32;
	if (FOR_CHECK)
		print_without_color(i);
	else
		print_field(i);
	exit(EXIT_SUCCESS);
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
