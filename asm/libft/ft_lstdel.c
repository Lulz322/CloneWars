/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 20:26:09 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/02/04 20:26:14 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (*alst == NULL)
		return ;
	if (*alst != NULL && del != NULL)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			tmp = *alst;
			(*alst) = (*alst)->next;
			free(tmp);
			tmp = NULL;
		}
	}
}
