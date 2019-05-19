/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:53:52 by iruban            #+#    #+#             */
/*   Updated: 2019/05/14 11:53:53 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void				lfork(t_kareta *kareta)
{
	t_kareta	*new;

	kareta->step += OP_LEN;
	new = copy_kareta(kareta, what_opp(kareta, 1, 1));
	new->next = g_gen.kareta;
	g_gen.kareta = new;
}
