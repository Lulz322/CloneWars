/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:00:17 by mbiliaie          #+#    #+#             */
/*   Updated: 2018/03/10 20:00:23 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_ln_tl_handler(char **line, int fd, char *fds[fd])
{
	char		*saver;
	size_t		st;
	size_t		len;
	size_t		line_size;

	len = ft_strlen(fds[fd]);
	if (ft_strchr(fds[fd], '\n'))
	{
		line_size = ft_strchr(fds[fd], '\n') - fds[fd];
		*line = ft_strsub(fds[fd], 0, line_size);
	}
	else
		*line = ft_strndup(fds[fd], len);
	st = ft_strchr(fds[fd], '\n') - fds[fd] + 1;
	if (ft_strchr(fds[fd], '\n'))
	{
		saver = fds[fd];
		fds[fd] = ft_strsub(fds[fd], (int)st, len);
		free(saver);
	}
	else
		ft_memdel((void *)&fds[fd]);
}

static int		ft_read_search(int fd, char *fds[fd])
{
	char	buffer[BUFF_SIZE + 1];
	char	*saver;
	ssize_t rct;

	while (!ft_strchr(fds[fd], '\n') && (rct = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		saver = fds[fd];
		buffer[rct] = '\0';
		fds[fd] = ft_strjoin(fds[fd], buffer);
		free(saver);
	}
	if (rct < 0)
		return (-1);
	else
		return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char *fds[4864];

	if (fd > 4864 || fd < 0 || line == NULL)
		return (-1);
	if (!fds[fd] && !(fds[fd] = ft_strnew(1)))
		return (-1);
	if (ft_read_search(fd, fds) == -1)
		return (-1);
	ft_ln_tl_handler(line, fd, fds);
	if (!fds[fd] && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
