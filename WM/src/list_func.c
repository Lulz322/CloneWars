#include "../includes/vm.h"

t_kareta *create_elem(int pos)
{
	static int id;
	t_kareta *elem;
	elem = (t_kareta *)malloc(sizeof(t_kareta));
	ft_bzero(elem, sizeof(t_kareta));
	elem->id = ++id;
	elem->pos = pos;
	return (elem);
}

void print_list(t_kareta *list)
{
	t_kareta *tmp;

	tmp = list;
	while (tmp)
	{
		printf("[%d]    |   Position : %-4d\n", tmp->id, tmp->pos);
		tmp= tmp->next;
	}
}

void add_elem(t_kareta **list, int pos)
{
	t_kareta *tmp;
	if (!*list)
	 *list = create_elem(pos);
	else
	{
		tmp = create_elem(pos);
		tmp->next = *list;
		*list = tmp;
	}
}
