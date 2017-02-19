/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 00:55:29 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/18 00:55:30 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	print_tiny_allocation(t_map *maps)
{
	t_data	*data;
	int		print;

	data = NULL;
	print = 0;
	while (maps)
	{
		if (maps->zone_type == TINY)
		{
			if (maps->data)
			{
				if (print == 0)
				{
					printf("TINY : %p\n", maps);
					print = 1;
				}
				data = maps->data;
				printf("%p - %p : %zu octets\n", data->ptr, \
					get_last_data(maps), get_allocated_data(maps));
			}
		}
		maps = maps->next;
	}
}

void	print_small_allocation(t_map *maps)
{
	t_data	*data;
	int		print;

	data = NULL;
	print = 0;
	while (maps)
	{
		if (maps->zone_type == SMALL)
		{
			if (maps->data)
			{
				if (print == 0)
				{
					printf("SMALL : %p\n", maps);
					print = 1;
				}
				data = maps->data;
				printf("%p - %p : %zu octets\n", data->ptr, \
					get_last_data(maps), get_allocated_data(maps));
			}
		}
		maps = maps->next;
	}
}

void	print_large_allocation(t_map *maps)
{
	t_data	*data;
	int		print;

	data = NULL;
	print = 0;
	while (maps)
	{
		if (maps->zone_type == LARGE)
		{
			if (maps->data)
			{
				if (print == 0)
				{
					printf("LARGE : %p\n", maps);
					print = 1;
				}
				data = maps->data;
				printf("%p - %p : %zu octets\n", data->ptr, \
					get_last_data(maps), get_allocated_data(maps));
			}
		}
		maps = maps->next;
	}
}

size_t	get_alloc_total(t_map *maps)
{
	int		allocated;
	t_data	*datas;

	allocated = 0;
	while (maps)
	{
		datas = maps->data;
		while (datas)
		{
			if (datas->is_free == FALSE)
				allocated += datas->allocated_size;
			datas = datas->next;
		}
		maps = maps->next;
	}
	return (allocated);
}

void	show_alloc_mem(void)
{
	t_map	*maps;

	maps = get_maps();
	if (maps != NULL)
	{
		print_tiny_allocation(maps);
		print_small_allocation(maps);
		print_large_allocation(maps);
	}
	printf("Total : %zu octets\n", get_alloc_total(maps));
}
