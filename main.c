#include "vm.h"
#include "libft/includes/libft.h"

void set_unknown(char *chmp)
{
	if (g_gen.f_champ.name[0] == '\0')
		_SET_CHAMP(g_gen.f_champ.name);
	if (g_gen.s_champ.name[0] == '\0')
		_SET_CHAMP(g_gen.s_champ.name);
	if (g_gen.t_champ.name[0] == '\0')
		_SET_CHAMP(g_gen.t_champ.name);
	if (g_gen.fh_champ.name[0] == '\0')
		_SET_CHAMP(g_gen.fh_champ.name);
}

void swap(char *first, char *second)
{
	char *tmp;
	tmp = first;
	first = second;
	second = tmp;
}

void set_champs(int a, char *chmp)
{
	if (a == 1)
		_SET_CHAMP(g_gen.f_champ.name);
	if (a == 2)
		_SET_CHAMP(g_gen.s_champ.name);
	if (a == 3)
		_SET_CHAMP(g_gen.t_champ.name);
	if (a == 4)
		_SET_CHAMP(g_gen.fh_champ.name);
}

void set_n(char *str, char *champ)
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
	if (number < 1 && number > 4)
		ERROR("Enter beetween 1 and 4");
	set_champs(number, champ);
}

/*void set_null_champs()
{
	g_gen.champs.champ_one = NULL;
	g_gen.champs.champ_two = NULL;
	g_gen.champs.champ_three = NULL;
	g_gen.champs.champ_four = NULL;
}
*/
void			parsing_argc(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			set_n(argv[i + 1], argv[i + 2]);
			i++;
		}
		else
			set_unknown(argv[i]);
	}
}

int main(int argc, char **argv)
{
	//set_null_champs();
	parsing_argc(argc, argv);
	printf("[0] : %-10s\n", g_gen.f_champ.name);
	printf("[1] : %-10s\n", g_gen.s_champ.name);
	printf("[2] : %-10s\n", g_gen.t_champ.name);
	printf("[3] : %-10s\n", g_gen.fh_champ.name);
}
