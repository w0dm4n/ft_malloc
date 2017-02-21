/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:42:21 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 17:42:35 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"
#include <stdio.h>

void	print_tiny_start(t_map *map)
{
	char	*addr;

	addr = get_addr(map);
	if (addr != NULL)
	{
		ft_putstr("TINY : ");
		ft_putstr(addr);
		ft_putstr("\n");
		free(addr);
	}
}

void	print_small_start(t_map *map)
{
	char	*addr;

	addr = get_addr(map);
	if (addr != NULL)
	{
		ft_putstr("SMALL : ");
		ft_putstr(addr);
		ft_putstr("\n");
		free(addr);
	}
}

void	print_large_start(t_map *map)
{
	char	*addr;

	addr = get_addr(map);
	if (addr != NULL)
	{
		ft_putstr("LARGE : ");
		ft_putstr(addr);
		ft_putstr("\n");
		free(addr);
	}
}

void	print_oct(void *ptr, t_data *data, size_t allocated)
{
	char	*first_addr;
	char	*second_addr;

	first_addr = get_addr(ptr);
	second_addr = get_addr((void*)data);
	if (first_addr != NULL && second_addr != NULL)
	{
		ft_putstr(first_addr);
		ft_putstr(" - ");
		ft_putstr(second_addr);
		ft_putstr(" : ");
		ft_putnbr(allocated);
		ft_putstr(" octets\n");
		free(first_addr);
		free(second_addr);
	}
}

void	print_total_oct(size_t octs)
{
	ft_putstr("Total : ");
	ft_putnbr(octs);
	ft_putstr(" octets\n");
}
