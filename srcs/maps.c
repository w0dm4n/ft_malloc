/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 21:34:34 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/17 21:34:35 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_map	*alloc_map(int zone, size_t size)
{
	t_map	*map;

	if (!(map = ft_mmap(sizeof(struct s_map))))
		return (NULL);
	map->prev = NULL;
	map->next = NULL;
	map->data = NULL;
	map->zone_type = zone;
	if (map->zone_type == TINY)
	{
		map->content = ft_mmap(TINY_ALLOC);
		map->content_data = ft_mmap(TINY_ALLOC + DATA);
	}
	else if (map->zone_type == SMALL)
	{
		map->content = ft_mmap(SMALL_ALLOC);
		map->content_data = ft_mmap(SMALL_ALLOC + DATA);
	}
	else
	{
		map->content = ft_mmap(size);
		map->content_data = ft_mmap(size + DATA);
	}
	return (map);
}

void	add_map(t_map *maps, t_map *new_map)
{
	if (maps)
	{
		while (maps->next)
			maps = maps->next;
		maps->next = new_map;
		new_map->prev = maps;
	}
	else
		g_maps = new_map;
}

t_map	*get_new_map(size_t size)
{
	t_map	*new;

	new = NULL;
	if (size <= (unsigned long)(TINY_ALLOC / 100))
		new = alloc_map(TINY, size);
	else if (size <= (unsigned long)(SMALL_ALLOC / 100))
		new = alloc_map(SMALL, size);
	else
		new = alloc_map(LARGE, size);
	if (new != NULL)
	{
		add_map(g_maps, new);
		return (new);
	}
	else
		return (NULL);
}

t_map	*get_map_by_size(size_t size, t_map *maps)
{
	while (maps)
	{
		if (size <= (TINY_ALLOC / (unsigned long)100) &&
			maps->zone_type == TINY)
		{
			if (map_available(maps, size))
				return (maps);
		}
		else if (size <= (unsigned long)(SMALL_ALLOC / 100) &&
			maps->zone_type == SMALL)
		{
			if (map_available(maps, size))
				return (maps);
		}
		maps = maps->next;
	}
	return (NULL);
}

int		map_available(t_map *map, size_t size)
{
	t_data	*datas;
	size_t	allocated;

	allocated = 0;
	datas = map->data;
	while (datas)
	{
		if (datas->is_free == FALSE)
			allocated += datas->allocated_size;
		datas = datas->next;
	}
	if (map->zone_type == TINY
		&& (allocated + size) > (unsigned long)TINY_ALLOC)
		return (FALSE);
	else if (map->zone_type == SMALL
		&& (allocated + size) > (unsigned long)SMALL_ALLOC)
		return (FALSE);
	return (TRUE);
}
