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

	if (ptr == NULL)
		return (malloc(size));
	if (!(data = find_data(ptr)))
		return (NULL);
	if (size <= data->allocated_size)
		return (ptr);
	tmp = ft_mmap(size);
	ft_bcopy((char*)ptr, (char*)tmp, data->allocated_size);
	munmap(ptr, data->allocated_size);
	if (size > (unsigned long)(TINY_ALLOC / 100))
		data->allocated_size = size;
	else
		data->allocated_size = (TINY_ALLOC / 100);
	data->ptr = tmp;
	return (tmp);
}

t_data	*get_new_data(size_t size, t_map *map)
{
	t_data	*new;

	if (!(new = get_ptr_data(map)))
		return (NULL);
	map->last_data = new;
	new->is_free = FALSE;
	new->real_size = size;
	new->next = NULL;
	new->prev = NULL;
	if (!(new->ptr = get_ptr(size, map)))
		return (NULL);
	if (map->zone_type == TINY)
		new->allocated_size = (TINY_ALLOC / 100);
	else if (map->zone_type == SMALL)
		new->allocated_size = (TINY_ALLOC / 100);
	else
	{
		new->allocated_size = size;
	}
	add_to_datas(new, map);
	return (new);
}

int		all_freed(t_data *datas)
{
	while (datas)
	{
		if (datas->is_free == FALSE)
			return (FALSE);
		datas = datas->next;
	}
	return (TRUE);
}
