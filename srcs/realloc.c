/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:43:37 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/19 12:43:38 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_bcopy(char *src, char *dest, int len)
{
	char	*lasts;
	char	*lastd;

	if (dest < src)
		while (len--)
			*dest++ = *src++;
	else
	{
		lasts = src + (len - 1);
		lastd = dest + (len - 1);
		while (len--)
			*(char *)lastd-- = *(char *)lasts--;
	}
}

void	*realloc(void *ptr, size_t size)
{
	t_data	*data;
	void	*tmp;

	if (!(data = find_data(ptr)))
		return (malloc(size));
	if (size <= data->allocated_size)
		return (ptr);
	tmp = ft_mmap(size);
	ft_bcopy((char*)ptr, (char*)tmp, data->allocated_size);
	munmap(ptr, data->allocated_size);
	data->allocated_size = data->allocated_size + size;
	data->ptr = tmp;
	return (tmp);
}
