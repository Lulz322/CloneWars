#include "../includes/vm.h"
#include <fcntl.h>

#define SIZE 255
bool	check_sound(int mod)
{
	char temp[255];
	static int fd;
	int counter;
	system("ps -j | grep afplay | wc -l > temp");
	fd = open("temp", O_RDONLY);
	read(fd, temp, SIZE);
	counter = ft_atoi(temp);
	//printf("[%d]\n", counter);
	close(fd);
	if (mod == 1)
		return ((counter == 2) ? true : false);
	else
		return ((counter == 3) ? true : false);
}
void set_death(void)
{
	if (check_sound(2))
		system("afplay died.wav&");
}

void set_music(void)
{
	if (check_sound(1))
		system("afplay music.wav&");
}

void kill_sounds(void) {
	system("killall afplay");
}
