#include "../../includes/vm.h"

void	big_letter_three(char c, t_champ a)
{
	if (c == 'V')
		ft_strcat(a.UKR_name, "В");
	if (c == 'W')
		ft_strcat(a.UKR_name, "ВВ");
	if (c == 'X')
		ft_strcat(a.UKR_name, "ИКС");
	if (c == 'Y')
		ft_strcat(a.UKR_name, "ВАЙ");
	if (c == 'Z')
		ft_strcat(a.UKR_name, "З");
}

void	big_letter_two(char c, t_champ a)
{
	if (c == 'L')
		ft_strcat(a.UKR_name, "Л");
	if (c == 'M')
		ft_strcat(a.UKR_name, "М");
	if (c == 'N')
		ft_strcat(a.UKR_name, "Н");
	if (c == 'O')
		ft_strcat(a.UKR_name, "О");
	if (c == 'P')
		ft_strcat(a.UKR_name, "П");
	if (c == 'Q')
		ft_strcat(a.UKR_name, "Ю");
	if (c == 'R')
		ft_strcat(a.UKR_name, "Р");
	if (c == 'S')
		ft_strcat(a.UKR_name, "С");
	if (c == 'T')
		ft_strcat(a.UKR_name, "Т");
	if (c == 'U')
		ft_strcat(a.UKR_name, "У");
	big_letter_three(c, a);
}
void	big_letter(char c, t_champ a)
{
	if (c == 'A')
		ft_strcat(a.UKR_name, "А");
	if (c == 'B')
		ft_strcat(a.UKR_name, "Б");
	if (c == 'C')
		ft_strcat(a.UKR_name, "Ц");
	if (c == 'D')
		ft_strcat(a.UKR_name, "Д");
	if (c == 'E')
		ft_strcat(a.UKR_name, "Е");
	if (c == 'F')
		ft_strcat(a.UKR_name, "Ф");
	if (c == 'H')
		ft_strcat(a.UKR_name, "Х");
	if (c == 'I')
		ft_strcat(a.UKR_name, "Й");
	if (c == 'J')
		ft_strcat(a.UKR_name, "ДЖ");
	if (c == 'K')
		ft_strcat(a.UKR_name, "К");
	big_letter_two(c, a);
}