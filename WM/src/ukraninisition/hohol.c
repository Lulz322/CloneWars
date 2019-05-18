#include "../includes/vm.h"

void	set_letters(char *str, t_champ a)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				what_is_a_letter(str[i], a);
			if (str[i] >= 'A' && str[i] <= 'Z')
				big_letter(str[i], a);
		}
		else
			ft_strncat(a.UKR_name, &str[i], 1);
	}
}

void	set_ukr_names(void)
{
	int i;
	t_champ a;

	i = 0;
	while (i < g_gen.am_champs)
	{
		a = g_gen.champ[i++];
		ft_bzero(a.UKR_name, 255);
		set_letters(a.name, a);
	}
}