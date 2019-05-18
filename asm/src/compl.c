/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <dlenskyi@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:47:17 by dlenskyi          #+#    #+#             */
/*   Updated: 2019/05/07 00:47:19 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*form_msg(char *result, char *title, const char *type)
{
	int		i;
	size_t	len;

	i = 1;
	len = type - title + i;
	ft_strncpy(result, title, len);
	return (result);
}

char			*validate_arg_title(char *title, size_t mode)
{
	struct s_hold f;

	f.result = NULL;
	if (!(f.type = ft_strrchr(title, '.')))
		return (f.type);
	if ((f.c1 = ft_strncmp(f.type, ".cor", mode)) &&
		(f.c2 = ft_strncmp(f.type, ".s", mode)))
		return (NULL);
	if (mode == 4 && !f.c1)
	{
		f.t = "s";
		f.result = ft_strnew(f.type - title + 2);
		mode = mode - 3;
	}
	else if (mode == 2 && !f.c2)
	{
		f.t = "cor";
		f.result = ft_strnew(f.type - title + 4);
		mode++;
	}
	else
		return (NULL);
	f.result = form_msg(f.result, title, f.type);
	ft_strncpy(ft_strrchr(f.result, '.') + 1, f.t, mode);
	return (f.result);
}
