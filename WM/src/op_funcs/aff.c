/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:09 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:10 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		aff(t_kareta *kareta)
{
	int32_t	reg;
	int32_t	qqq;

	kareta->step += OP_LEN + ARG_LEN;
	reg = g_gen.field[adress(kareta->pos + kareta->step)];
	qqq = kareta->reg[reg - 1];
	kareta->step += REG_LEN;
	if (g_gen.aff && !g_gen.flag_visual)
		ft_printf("%c\n", (char)qqq);
}
