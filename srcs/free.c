/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 04:20:26 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/18 04:20:27 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	update_data(t_map *map, t_data *data)
{
	t_data	*datas;
	t_data	*start;

	datas = map->data;
	start = data;
	while (datas)
	{
		if (datas == data)
		{
			datas = data;
			break ;
		}
		datas = datas->next;
	}
	map->data = start;
}

void	remove_data(t_data **ptr, t_data *data)
{
	t_data	tmp;

	while ((*ptr) != NULL)
	{
		if ((*ptr) == data)
		{
			tmp = **ptr;
			*ptr = (*ptr)->next;
			munmap(ptr, sizeof(ptr));
		}
		else
		{
			ptr = &((*ptr)->next);
		}
	}
}

void	delete_from_map(t_data *data, t_map *map)
{
	munmap(data->ptr, data->allocated_size);
	remove_data(&map->data, data);
	// free map if data empty
}

void	get_data(void *ptr)
{
	t_map	*maps;
	t_data	*datas;

	datas = NULL;
	maps = get_maps();
	while (maps)
	{
		datas = maps->data;
		while (datas)
		{
			if (datas->ptr == ptr)
			{
				delete_from_map(datas, maps);
				break ;
			}
			datas = datas->next;
		}
		maps = maps->next;
	}
}

void	free(void *ptr)
{
	if (ptr != NULL)
	{
		get_data(ptr);
	}
}
