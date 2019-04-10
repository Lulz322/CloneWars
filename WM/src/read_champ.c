#include "../includes/vm.h"
#include <fcntl.h>
#include <stdint.h>

int32_t	bytecode_to_int32(uint8_t *bytecode, int size)
{
	int32_t	result;
	int		sign;
	int		i;

	result = 0;
	sign = (int)(bytecode[0] & 0x80);
	i = 0;
	while (size)
	{
		if (sign)
			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
		else
			result += bytecode[size - 1] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

char	*check_name(int fd, int len)
{
	int		size;
	char	*buffer;

	if (!(buffer = ft_strnew(len)))
		ERROR("Memory error");
	size = read(fd, buffer, len);
	if (size < len)
		ERROR("ERROR_FILE");
	return (buffer);
}

int32_t	check_int(int fd)
{
	int		size;
	uint8_t	buffer[4];

	size = read(fd, &buffer, 4);
	if (size == -1 || size < 4)
		ERROR("ERROR_FILE");
	return (bytecode_to_int32(buffer, 4));
}

uint8_t	*check_code(int fd, int len)
{
	ssize_t	size;
	uint8_t	*buffer;
	uint8_t	byte;

	if (!(buffer = malloc(len)))
		ERROR("Memory error");
	size = read(fd, buffer, len);
	if (size == -1)
		ERROR("ERROR_FILE");
	if (size < (ssize_t)len || read(fd, &byte, 1) != 0)
		ERROR("ERROR_FILE");
	return (buffer);
}

void read_champ(int a, char *file_name)
{
	int fd;

	ft_strcat(g_gen.champ[a].file_name, file_name);
	fd = open(file_name, O_RDONLY);
	if (check_int(fd) != COREWAR_EXEC_MAGIC)
		ERROR("ZA SHO?");
	ft_strcat(g_gen.champ[a].name, check_name(fd, PROG_NAME_LENGTH));
	if (check_int(fd) != 0)
		ERROR("ERROR_FILE");
	if ((g_gen.champ[a].length = check_int(fd)) < 0 || g_gen.champ[a].length > CHAMP_MAX_SIZE)
		ERROR("ERROR SIZE")
	ft_strcat(g_gen.champ[a].comment, check_name(fd, COMMENT_LENGTH));
	if (check_int(fd) != 0)
		ERROR("ERROR");
	g_gen.champ[a].algo = check_code(fd, g_gen.champ[a].length);
}
