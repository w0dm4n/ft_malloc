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

t_map	*alloc_map(int zone)
{
	t_map	*map;

	if (!(map = ft_mmap(sizeof(struct s_map*))))
		return (NULL);
	map->prev = NULL;
	map->next = NULL;
	map->data = NULL;
	map->zone_type = zone;
	return (map);
}

t_map	*get_maps()
{
	return (g_maps);
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
	if (size <= (TINY_ALLOC / 100))
		new = alloc_map(TINY);
	else if (size <= (SMALL_ALLOC / 100))
		new = alloc_map(SMALL);
	else
		new = alloc_map(LARGE);
	if (new != NULL)
	{
		add_map(get_maps(), new);
		return (new);
	}
	else
		return (NULL);
}

t_map	*get_map_by_size(size_t size, t_map	*maps)
{
	while (maps)
	{
		if (size <= (TINY_ALLOC / 100) &&
		 maps->zone_type == TINY)
		{
			if (map_available(maps, size))
				return (maps);
		}
		else if (size <= (SMALL_ALLOC / 100) &&
			maps->zone_type == SMALL)
		{
			if (map_available(maps, size))
				return (maps);
		}
		maps = maps->next;
	}
	return NULL;
}

int		map_available(t_map *map, size_t size)
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
	if (map->zone_type == TINY
		&& (allocated + size) > TINY_ALLOC)
		return (FALSE);
	else if (map->zone_type == SMALL
		&& (allocated + size) > SMALL_ALLOC)
		return (FALSE);
	return (TRUE);
}













