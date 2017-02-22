/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:48:51 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 18:49:04 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	print_ascii(int size, void *ptr)
{
	int i;

	i = 0;
	while (i < size && i < 16)
	{
		if ((*(char*)ptr) > 33 && (*(char*)ptr) < 127)
			ft_putchar((*(char*)ptr));
		else
			ft_putchar('.');
		ptr++;
		i++;
	}
}

int		print_hexa_data(t_data *s)
{
	void	*ptr;
	size_t	i;
	char	*tmp;
	size_t	count;

	ptr = s->ptr;
	i = 0;
	count = 0;
	while (i < s->real_size)
	{
		if (s->is_free == FALSE)
		{
			tmp = get_and_print_first(tmp, ptr);
			tmp = get_and_print_second(tmp, ptr);
			ft_putstr(" ");
			count++;
			count = check_count(count, ptr);
		}
		ptr++;
		i++;
		ft_putnbr(i);
	}
	i = print_end_hexa(count, ptr, i);
	return (count);
}

void	show_hexa_tiny(void)
{
	t_map	*maps;
	t_data	*datas;

	maps = g_maps;
	while (maps)
	{
		if (maps->zone_type == TINY)
		{
			datas = maps->data;
			while (datas)
			{
				if (datas->is_free == FALSE)
					print_hexa_data(datas);
				datas = datas->next;
			}
		}
		maps = maps->next;
	}
}

void	show_hexa_small(void)
{
	t_map	*maps;
	t_data	*datas;

	maps = g_maps;
	while (maps)
	{
		if (maps->zone_type == SMALL)
		{
			datas = maps->data;
			while (datas)
			{
				if (datas->is_free == FALSE)
					print_hexa_data(datas);
				datas = datas->next;
			}
		}
		maps = maps->next;
	}
}

void	show_hexa_large(void)
{
	t_map	*maps;
	t_data	*datas;

	maps = g_maps;
	while (maps)
	{
		if (maps->zone_type == LARGE)
		{
			datas = maps->data;
			while (datas)
			{
				if (datas->is_free == FALSE)
					print_hexa_data(datas);
				datas = datas->next;
			}
		}
		maps = maps->next;
	}
}
