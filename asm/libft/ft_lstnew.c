/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:18:27 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/01/04 19:18:30 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlst;

	nlst = (t_list*)malloc(sizeof(t_list));
	if (nlst == NULL)
		return (NULL);
	if (content != NULL)
	{
		nlst->content = malloc(content_size);
		if (nlst->content == NULL)
		{
			free(nlst);
			return (NULL);
		}
		ft_memcpy(nlst->content, content, content_size);
		nlst->content_size = content_size;
	}
	else
	{
		nlst->content = NULL;
		nlst->content_size = 0;
	}
	nlst->next = NULL;
	return (nlst);
}
