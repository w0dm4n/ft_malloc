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
	void *ptr = get_alloc(size);
	return (ptr != NULL) ? ptr : NULL;
}

void	*get_alloc(size_t size)
{
	t_map	*maps = get_maps();
	t_map	*current;

	current = NULL;
	if (!maps)
		current = get_new_map(size);
	if (g_maps)
	{
		if (current == NULL)
		{
			if ((current = get_map_by_size(size, get_maps())) == NULL)
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
	t_data *test = map->data;
	return (data->ptr);
}

/*
void	*realloc(void *ptr, size_t size)
{
	/*t_map	*maps;
	t_data	*data;
	int res = 0;
	int res1 = 0;

	data = NULL;
	maps = get_maps();
	printf("%p\n", ptr);
	while (maps)
	{
		data = maps->data;
		printf("%p\n", data->ptr);
		res1 = munmap(data->ptr, data->allocated_size);
		res = munmap(data, sizeof(data));

		printf("result: %d, result1: %d", res, res1);
		maps = maps->next;
	}
	return (NULL);
}
*/






