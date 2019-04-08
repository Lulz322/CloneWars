#include "vm.h"
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

void read_champ(int a, char *file_name)
{
	int fd;
	fd = open(file_name, O_RDONLY);
	if (check_int(fd) != COREWAR_EXEC_MAGIC)
		ERROR("ZA SHO?");
	 ft_strcat(g_gen.champ[a].name, check_name(fd, PROG_NAME_LENGTH));
	 ft_strcat(g_gen.champ[a].comment, check_name(fd, COMMENT_LENGTH));
}
