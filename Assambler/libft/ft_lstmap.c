/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:10:09 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/01/05 22:10:14 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	first = NULL;
	new = NULL;
	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		first = new;
		while (lst->next != NULL)
		{
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
	}
	return (first);
}
