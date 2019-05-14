/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:01:31 by iruban            #+#    #+#             */
/*   Updated: 2019/04/24 13:01:32 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <fcntl.h>

#define SIZE 255

bool	check_sound(int mod)
{
	char		temp[255];
	static int	fd;
	int			counter;

	system("ps -j | grep afplay | wc -l > temp");
	fd = open("temp", O_RDONLY);
	read(fd, temp, SIZE);
	counter = ft_atoi(temp);
	close(fd);
	if (mod == 1)
		return ((counter == 2) ? true : false);
	else
		return ((counter == 3) ? true : false);
}

void	set_death(void)
{
	if (ST.flag_visual && ST.sounds && check_sound(2))
		system("afplay died.wav&");
}

void	jason_born(void)
{
	if (ST.flag_visual && ST.sounds && check_sound(2))
		system("afplay born.wav&");
}

void	set_music(void)
{
	if (ST.flag_visual && ST.sounds && check_sound(1))
		system("afplay music2.wav&");
}

void	kill_sounds(void)
{
	system("killall afplay");
}
