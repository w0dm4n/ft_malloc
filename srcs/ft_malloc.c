/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:30:38 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/17 19:30:41 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*ft_mmap(size_t size)
{
	return (mmap(0, size, PROT_READ | PROT_WRITE, \
		MAP_ANONYMOUS | MAP_PRIVATE, FILE_DESCRIPTOR, OFFSET));
}

void	*malloc(size_t size)
{
	void	*ptr;

	ptr = get_alloc(size);
	return (ptr != NULL) ? ptr : NULL;
}

void	*get_alloc(size_t size)
{
	t_map	*maps;
	t_map	*current;

	current = NULL;
	maps = g_maps;
	if (!maps)
		current = get_new_map(size);
	if (g_maps)
	{
		if (current == NULL)
		{
			if ((current = get_map_by_size(size, g_maps)) == NULL)
				current = get_new_map(size);
		}
		if (current)
		{
			if (!map_available(current, size))
				current = get_new_map(size);
			return (alloc_in_map(size, current));
		}
	}
	return (NULL);
}

void	*alloc_in_map(size_t size, t_map *map)
{
	t_data	*data;

	if (!(data = get_new_data(size, map)))
		return (NULL);
	return (data->ptr);
}

t_data	*find_data(void *ptr)
{
	t_map	*maps;
	t_data	*datas;

	maps = g_maps;
	datas = NULL;
	while (maps)
	{
		if (maps->data)
		{
			datas = maps->data;
			while (datas)
			{
				if (datas->ptr == ptr)
					return (datas);
				datas = datas->next;
			}
		}
		maps = maps->next;
	}
	return (NULL);
}
