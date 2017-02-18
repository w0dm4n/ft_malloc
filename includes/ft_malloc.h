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

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <unistd.h>
# include <string.h>
# include <sys/mman.h>
# include "struct.h"
# include <stdio.h>

# define FILE_DESCRIPTOR -1
# define OFFSET 0
# define PAGE_SIZE getpagesize()
# define TINY_ALLOC (PAGE_SIZE / 4) * 100
# define SMALL_ALLOC (PAGE_SIZE * 1) * 100
# define TRUE 1
# define FALSE 0

void	*malloc(size_t size);
t_map	*get_maps();
void	*get_alloc(size_t size);
void	*ft_mmap(size_t size);
t_map	*get_map_by_size(size_t size, t_map	*maps);
t_map	*get_new_map(size_t size);
void	*alloc_in_map(size_t size, t_map *map);
int		map_available(t_map *map, size_t size);

t_data	*get_new_data(size_t size, t_map *map);
void	add_to_datas(t_data	*data, t_map *map);
t_data	*get_last_data(t_map *map);
size_t	get_allocated_data(t_map *map);

void	show_alloc_mem(void);
void	free(void *ptr);
t_map	*g_maps;
#endif
