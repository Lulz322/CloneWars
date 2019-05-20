/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:48:28 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 12:48:29 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <fcntl.h>
#include <stdint.h>

char		*check_name(int fd, int len)
{
	int		size;
	char	*buffer;

	ERROR_MALLOC((buffer = ft_strnew(len)));
	size = read(fd, buffer, len);
	READING(size < len, "Error Name/Comment");
	return (buffer);
}

int32_t		check_bytes(int fd)
{
	int		size;
	uint8_t	buffer[4];

	size = read(fd, &buffer, 4);
	READING(size == -1 || size < 4, "Size Error, U're so FAT");
	return (bytecode_to_int32(buffer, 4));
}

uint8_t		*check_algo(int fd, int len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	ERROR_MALLOC(buffer = malloc(len));
	size = read(fd, buffer, len);
	READING(size == -1, "SIZE ERROR");
	READING(size < (ssize_t)len || read(fd, &byte, 1) != 0,
			"Invalid Exucation Code");
	return (buffer);
}

void		read_champ(int a, char *file_name)
{
	int fd;

	ft_strcat(g_gen.champ[a].file_name, file_name);
	fd = open(file_name, O_RDONLY);
	READING(check_bytes(fd) != COREWAR_EXEC_MAGIC, "Magic isn't Power :(");
	g_gen.champ[a].name = check_name(fd, PROG_NAME_LENGTH);
	READING(check_bytes(fd) != 0, "Missing Zero Byte");
	READING(((g_gen.champ[a].length = check_bytes(fd)) < 0
		|| g_gen.champ[a].length > CHAMP_MAX_SIZE), "Error Champ Size");
	g_gen.champ[a].comment = check_name(fd, COMMENT_LENGTH);
	READING(check_bytes(fd) != 0, "Missing Zero Byte");
	g_gen.champ[a].algo = check_algo(fd, g_gen.champ[a].length);
}
