/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:43:30 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 12:43:31 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	set_unknown(char *chmp)
{
	if (!g_gen.champ[0].name)
		READ_CHAMP(0, chmp);
	if (!g_gen.champ[1].name)
		READ_CHAMP(1, chmp);
	if (!g_gen.champ[2].name)
		READ_CHAMP(2, chmp);
	if (!g_gen.champ[3].name)
		READ_CHAMP(3, chmp);
}

void	set_n(char *str, char *where)
{
	int number;
	int kuda;

	kuda = check_where(where);
	if (kuda > 4 || kuda < 1)
		ERROR("ERROR");
	number = 0;
	while (number < 4)
	{
		if (ft_strequ(g_gen.champ[number].file_name, str))
			break ;
		number++;
	}
	if (g_gen.champ[number].hard_set == true
		|| g_gen.champ[kuda].hard_set == true)
		ERROR("DUPLICATE");
	g_gen.champ[kuda].hard_set = true;
	swap(&g_gen.champ[number], &g_gen.champ[kuda - 1]);
}

void	set_numbers(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			set_n(argv[i + 2], argv[i + 1]);
			i++;
		}
	}
}

void	set_dump(char *str, int d)
{
	int		a;
	char	*tmp;

	if (!str || g_gen.flag_dump == true || g_gen.flag_d == true)
		ERROR("ERROR INPUT");
	a = ft_atoi(str);
	tmp = ft_itoa(a);
	if (!ft_strequ(tmp, str))
	{
		free(tmp);
		ERROR("Enter a number!");
	}
	free(tmp);
	SET_DUMPS(d);
}

void	parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			i++;
		else if (ft_strequ(argv[i], "-dump"))
			set_dump(argv[i++ + 1], 1);
		else if (ft_strequ(argv[i], "-d"))
			set_dump(argv[i++ + 1], 2);
		else if (ft_strequ(argv[i], "-v"))
			g_gen.flag_visual = true;
		else if (ft_strequ(argv[i], "-l"))
			set_dump(argv[i++ + 1], 3);
		else if (ft_strequ(argv[i], "-a"))
			g_gen.aff = 1;
		else if (ft_strequ(argv[i], "-peremoga"))
			g_gen.f_p = true;
		else if (ft_strequ(argv[i], "-s"))
			g_gen.sounds = true;
		else
			set_unknown(argv[i]);
	}
	set_numbers(argc, argv);
}
