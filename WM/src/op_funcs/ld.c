/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:35 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:36 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				ld(t_kareta *kareta)
{
	int32_t	value;
	int32_t	reg;

	kareta->step += OP_LEN + ARG_LEN;
	LD;
	reg = ST.field[adress(kareta->pos + kareta->step)];
	LD2;
}
