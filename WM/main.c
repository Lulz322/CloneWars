#include "vm.h"

void set_unknown(char *chmp)
{
	if (ft_strequ(g_gen.champ[0].name, "\0"))
		_READ_CHAMP(0, chmp);
	if (g_gen.champ[1].name[0] == '\0')
		_READ_CHAMP(1, chmp);
	if (g_gen.champ[2].name[0] == '\0')
		_READ_CHAMP(2, chmp);
	if (g_gen.champ[3].name[0] == '\0')
		_READ_CHAMP(3, chmp);
}

void swap(t_champ *first, t_champ *second)
{
	t_champ tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

void set_n(char *str, int kuda)
{
	char *tmp;
	int number;

	if (!ft_isdigit(str[0]))
		ERROR("Error number");
	number = ft_atoi(str);
	tmp = ft_itoa(number);
	if (!ft_strequ(str, tmp))
	{
		free(tmp);
		ERROR("Error number");
	}
	if (number < 1 || number > 4)
		ERROR("Enter beetween 1 and 4");
	swap(&g_gen.champ[number - 1], &g_gen.champ[kuda]);
}

void set_numbers(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			set_n(argv[i + 1], i - 1);
			i++;
		}
	}
}

void			parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			i++;
		else
			set_unknown(argv[i]);
	}
}


int main(int argc, char **argv)
{
	parsing_argc(argc, argv);
	set_numbers(argc, argv);
	printf("[1] : %-25s\n", g_gen.champ[0].name);
	printf("[2] : %-25s\n", g_gen.champ[1].name);
	printf("[3] : %-25s\n", g_gen.champ[2].name);
	printf("[4] : %-25s\n", g_gen.champ[3].name);
}
