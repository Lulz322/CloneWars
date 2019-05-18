#include "../../includes/vm.h"

void	what_is_a_letter_three(char c, t_champ a)
{
	if (c == 'v')
		ft_strcat(a.UKR_name, "в");
	if (c == 'w')
		ft_strcat(a.UKR_name, "вв");
	if (c == 'x')
		ft_strcat(a.UKR_name, "икс");
	if (c == 'y')
		ft_strcat(a.UKR_name, "вай");
	if (c == 'z')
		ft_strcat(a.UKR_name, "з");
}

void	what_is_a_letter_two(char c, t_champ a)
{
	if (c == 'l')
		ft_strcat(a.UKR_name, "л");
	if (c == 'm')
		ft_strcat(a.UKR_name, "м");
	if (c == 'n')
		ft_strcat(a.UKR_name, "н");
	if (c == 'o')
		ft_strcat(a.UKR_name, "о");
	if (c == 'p')
		ft_strcat(a.UKR_name, "п");
	if (c == 'q')
		ft_strcat(a.UKR_name, "ю");
	if (c == 'r')
		ft_strcat(a.UKR_name, "р");
	if (c == 's')
		ft_strcat(a.UKR_name, "с");
	if (c == 't')
		ft_strcat(a.UKR_name, "т");
	if (c == 'u')
		ft_strcat(a.UKR_name, "у");
	what_is_a_letter_three(c, a);
}
void	what_is_a_letter(char c, t_champ a)
{
	if (c == 'a')
		ft_strcat(a.UKR_name, "a");
	if (c == 'b')
		ft_strcat(a.UKR_name, "б");
	if (c == 'c')
		ft_strcat(a.UKR_name, "ц");
	if (c == 'd')
		ft_strcat(a.UKR_name, "д");
	if (c == 'e')
		ft_strcat(a.UKR_name, "е");
	if (c == 'f')
		ft_strcat(a.UKR_name, "ф");
	if (c == 'h')
		ft_strcat(a.UKR_name, "х");
	if (c == 'i')
		ft_strcat(a.UKR_name, "й");
	if (c == 'j')
		ft_strcat(a.UKR_name, "дж");
	if (c == 'k')
		ft_strcat(a.UKR_name, "к");
	what_is_a_letter_two(c, a);
}