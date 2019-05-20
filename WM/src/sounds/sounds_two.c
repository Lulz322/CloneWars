/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:22:39 by iruban            #+#    #+#             */
/*   Updated: 2019/05/20 12:22:50 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	set_winner(void)
{
	if (g_gen.flag_visual && g_gen.sounds && check_sound(1))
	{
		system("killall afplay");
		if (g_gen.f_p)
			system("afplay sounds/music.wav&");
		else
			system("afplay sounds/winner.mp3&");
	}
}
