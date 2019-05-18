/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iruban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 11:40:05 by iruban            #+#    #+#             */
/*   Updated: 2019/04/22 11:40:06 by iruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void		int_to_byte(int32_t addr, int32_t value, int32_t size)
{
	int8_t i;

	i = 0;
	while (size)
	{
		g_gen.field[adress(addr + size - 1)] =
			(uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int32_t		byte_to_int(int32_t addr, int32_t size)
{
	int32_t		result;
	uint8_t		sign;
	int			i;

	i = 0;
	result = 0;
	sign = (g_gen.field[adress(addr)] & 0x80);
	while (size)
	{
		if (sign)
			result += ((g_gen.field[adress(addr + size - 1)] ^ 0xFF) <<
					(i++ * 8));
		else
			result += g_gen.field[adress(addr + size - 1)] << (i++ * 8);
		size--;
	}
	if (sign)
		result = ~(result);
	return (result);
}

int32_t		bytecode_to_int32(uint8_t *bytecode, int size)
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
