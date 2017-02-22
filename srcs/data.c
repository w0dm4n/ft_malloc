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

void	*get_ptr(size_t size, t_map *map)
{
	int		allocated;
	t_data	*datas;

	datas = map->data;
	allocated = 0;
	while (datas)
	{
		allocated += datas->allocated_size;
		datas = datas->next;
	}
	size = 0;
	allocated += 1;
	return (map->content + allocated);
}

void	*get_ptr_data(t_map *map)
{
	if (map->last_data)
		return (map->last_data + sizeof(struct s_data));
	return (map->content_data);
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
		if (datas->is_free == FALSE)
			allocated += datas->real_size;
		datas = datas->next;
	}
	return (allocated);
}
