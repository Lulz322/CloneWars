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
	kareta->step += OP_LEN + ARG_LEN;
	if (g_gen.aff && !g_gen.flag_visual)
		ft_printf("%c\n", (char)kareta->reg[set_reg(kareta) - 1]);
}
