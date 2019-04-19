#include "../includes/vm.h"

t_kareta *create_elem(int pos)
{
	static int id;
	t_kareta *elem;
	elem = (t_kareta *)malloc(sizeof(t_kareta));
	ft_bzero(elem, sizeof(t_kareta));
	elem->id = ++id;
	elem->reg[0] = -id;
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

t_kareta	*copy_kareta(t_kareta *cursor, int32_t addr)
{
	t_kareta	*new;
	int			i;

	new = create_elem(find_adress(cursor->pos + addr));
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = cursor->reg[i];
	new->carry = cursor->carry;
	new->last_alive = cursor->last_alive;
	return (new);
}