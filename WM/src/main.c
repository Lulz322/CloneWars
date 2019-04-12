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
	int a;

	a = -1;
	ft_printf("Introducing contestants...\n");
	while (g_gen.champ[++a].length)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", a + 1, st.champ[a].length, st.champ[a].name, st.champ[a].comment);
}
int main(int argc, char **argv)
{
	parsing_argc(argc, argv);
	set_numbers(argc, argv);
	_ERR_CHAMP(g_gen.champ[0].length);
	print_info_champs();
	create_field();
	set_karetu();

}
