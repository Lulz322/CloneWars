#include "../includes/vm.h"

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
	int number;

	if (kuda > 4 || kuda < 0)
		ERROR("ERROR")
	number = 0;
	while(number < 4)
	{
		if (ft_strequ(g_gen.champ[number].file_name, str))
			break;
		number++;
	}
	if (g_gen.champ[number].hard_set == true
		|| g_gen.champ[kuda].hard_set == true)
		ERROR("DUPLICATE");
	g_gen.champ[number].hard_set = true;
	swap(&g_gen.champ[number], &g_gen.champ[kuda]);
}

void set_numbers(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			set_n(argv[i + 2], ft_atoi(argv[i + 1]) - 1);
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

void print_info_champs() {
	printf("[1] : %-25.25s   | %-20.20s  |  %-25.25s [%d]\n", g_gen.champ[0].name, g_gen.champ[0].file_name, g_gen.champ[0].comment, g_gen.champ[0].hard_set);
	printf("[2] : %-25.25s   | %-20.20s  |  %-25.25s [%d]\n", g_gen.champ[1].name, g_gen.champ[1].file_name, g_gen.champ[1].comment, g_gen.champ[1].hard_set);
	printf("[3] : %-25.25s   | %-20.20s  |  %-25.25s [%d]\n", g_gen.champ[2].name, g_gen.champ[2].file_name, g_gen.champ[2].comment, g_gen.champ[2].hard_set);
	printf("[4] : %-25.25s   | %-20.20s  |  %-25.25s [%d]\n", g_gen.champ[3].name, g_gen.champ[3].file_name, g_gen.champ[3].comment, g_gen.champ[3].hard_set);
}
int main(int argc, char **argv)
{
	parsing_argc(argc, argv);
	set_numbers(argc, argv);
	print_info_champs();
	create_field();

}
