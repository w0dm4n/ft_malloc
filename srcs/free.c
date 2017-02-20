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

void	remove_data(t_data **ptr, t_data *data)
{
	t_data	tmp;

	while ((*ptr) != NULL)
	{
		if ((*ptr) == data)
		{
			tmp = **ptr;
			*ptr = (*ptr)->next;
			munmap(data, sizeof(data));
		}
		else
		{
			ptr = &((*ptr)->next);
		}
	}
}

void	free_all(t_map *map)
{
	if (map->zone_type == TINY)
	{
		munmap(map->content, TINY_ALLOC);
		munmap(map->content_data, TINY_ALLOC + DATA);
	}
	else if (map->zone_type == SMALL)
	{
		munmap(map->content, SMALL_ALLOC);
		munmap(map->content_data, SMALL_ALLOC + DATA);
	}
	else
	{
		munmap(map->content, map->data->allocated_size);
		munmap(map->content_data, map->data->allocated_size + DATA);
	}
	munmap(map, sizeof(struct s_map));
}

void	remove_map(t_map **ptr, t_map *map)
{
	t_map	tmp;

	while ((*ptr) != NULL)
	{
		if ((*ptr) == map)
		{
			tmp = **ptr;
			*ptr = (*ptr)->next;
			free_all(map);
		}
		else
		{
			ptr = &((*ptr)->next);
		}
	}
}

int		delete_from_map(t_data *data, t_map *map)
{
	data->is_free = TRUE;
	if (all_freed(map->data) == TRUE && map_available(map, 1024) == FALSE)
	{
		remove_map(&g_maps, map);
		return (TRUE);
	}
	return (FALSE);
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
				if (delete_from_map(datas, maps) == TRUE)
					maps = get_maps();
				break ;
			}
			datas = datas->next;
		}
		if (maps != NULL)
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
