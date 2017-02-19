/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 23:14:04 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/17 23:14:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data	*get_new_data(size_t size, t_map *map)
{
	t_data	*new;

	if (!(new = ft_mmap(sizeof(struct s_data*))))
		return (NULL);
	new->is_free = FALSE;
	new->next = NULL;
	new->prev = NULL;
	if (!(new->ptr = ft_mmap(size)))
		return (NULL);
	new->allocated_size = size;
	add_to_datas(new, map);
	return (new);
}

void	add_to_datas(t_data *data, t_map *map)
{
	t_data	*datas;

	datas = map->data;
	if (datas != NULL)
	{
		while (datas->next)
			datas = datas->next;
		datas->next = data;
		data->prev = datas;
	}
	else
		map->data = data;
}

t_data	*get_last_data(t_map *map)
{
	t_data	*datas;

	datas = map->data;
	while (datas->next)
	{
		datas = datas->next;
	}
	return (datas);
}

size_t	get_allocated_data(t_map *map)
{
	t_data	*datas;
	size_t	allocated;

	allocated = 0;
	datas = map->data;
	while (datas)
	{
		allocated += datas->allocated_size;
		datas = datas->next;
	}
	return (allocated);
}

t_data	*find_data(void *ptr)
{
	t_map	*maps;
	t_data	*datas;

	maps = get_maps();
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
