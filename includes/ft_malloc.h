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

# define FILE_DESCRIPTOR -1
# define OFFSET 0
# define PAGE_SIZE getpagesize()
# define TINY_ALLOC (PAGE_SIZE / 4) * 100
# define SMALL_ALLOC (PAGE_SIZE * 8) * 100
# define TRUE 1
# define FALSE 0
# define DATA 1000000

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
t_data	*find_data(void *ptr);
void	*get_ptr(size_t size, t_map *map);
void	*get_ptr_data(t_map *map);

void	*realloc(void *ptr, size_t size);
void	print_total_oct(size_t octs);

void	show_alloc_mem(void);
int		all_freed(t_data *datas);
void	free(void *ptr);
int		is_available(t_map *map, size_t size);

void	ft_putchar(char c);
void	ft_putnbr(long int nbr);
void	ft_putstr(char *str);
char	*ft_strnew(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_itoabase_uint(unsigned long int nbr, char *base);
size_t	ft_strlen(const char *s);

void	print_tiny_start(t_map	*map);
void	print_small_start(t_map	*map);
void	print_large_start(t_map	*map);
void	print_oct(void *ptr, t_data *data, size_t allocated);
void	show_hexa_tiny(void);
void	show_hexa_small(void);
void	show_hexa_large(void);

void	print_ascii(int size, void *ptr);
int		print_end_hexa(size_t count, void *ptr, int i);
char	*get_and_print_first(char *tmp, void *ptr);
char	*get_and_print_second(char *tmp, void *ptr);
size_t	check_count(size_t count, void *ptr);

char	*get_addr(void	*ptr);
t_map	*g_maps;
#endif
