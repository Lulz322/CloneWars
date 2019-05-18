/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gd_static.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiliaie <mbiliaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 00:48:15 by mbiliaie          #+#    #+#             */
/*   Updated: 2019/05/07 00:48:21 by mbiliaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

ssize_t			display_static(long num_data, void *storage, size_t bt_count)
{
	size_t				stated;
	ssize_t				posted;
	size_t				doub_md;
	size_t				quad_md;
	long int			idf;

	doub_md = 2;
	idf = num_data;
	quad_md = 4;
	if (bt_count == doub_md)
		stated = make_backwards_1(*(unsigned int*)storage);
	if (bt_count == quad_md)
		stated = make_backwards_2(*(unsigned int*)storage);
	if (bt_count != doub_md && bt_count != quad_md)
		stated = *(unsigned int*)storage;
	posted = write(idf, &stated, bt_count);
	return (posted);
}

size_t			get_into_2(long num_data)
{
	size_t				obj;
	size_t				result;
	long int			idf;
	size_t				quad_md;

	quad_md = 4;
	idf = num_data;
	read(num_data, &obj, quad_md);
	result = make_backwards_2(obj);
	return (result);
}

size_t			get_into_1(long num_data)
{
	size_t				obj;
	size_t				result;
	long int			idf;
	size_t				doub_md;

	doub_md = 2;
	idf = num_data;
	read(idf, &obj, doub_md);
	result = make_backwards_1(obj);
	return (result);
}
