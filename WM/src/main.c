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

int check_where(char *where) {
	int a;
	char *tmp;

	if (!where)
		ERROR("O_o");
	a = ft_atoi(where);
	tmp = ft_itoa(a);
	if (!ft_strequ(tmp, where))
	{
		free(tmp);
		ERROR("Enter a number!");
	}
	free(tmp);
	return (a);
}

void set_n(char *str, char *where)
{
	int number;
	int kuda;

	kuda = check_where(where);
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
			set_n(argv[i + 2], argv[i + 1]);
			i++;
		}
	}
}

void set_dump(char *str)
{
	int a;
	char *tmp;

	if (!str || st.flag_dump == true)
		ERROR("ERROR INPUT");
	a = ft_atoi(str);
	tmp = ft_itoa(a);
	if (!ft_strequ(tmp, str))
	{
		free(tmp);
		ERROR("Enter a number!");
	}
	free(tmp);
	st.flag_dump = true;
	st.flag_dump_d = a;
}

void			parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			i++;
		else if (ft_strequ(argv[i], "-dump"))
			set_dump(argv[i++ + 1]);
		else
			set_unknown(argv[i]);
	}
}

void free_struct() {
	int a;

	a = -1;
	while (st.champ[++a].length)
	{
		free(st.champ[a].name);
		free(st.champ[a].comment);
	}
}

int main(int argc, char **argv)
{
	parsing_argc(argc, argv);
	set_numbers(argc, argv);
	_ERR_CHAMP(g_gen.champ[0].length);
	create_field();
	set_karetu();
	system("leaks corewar");
}