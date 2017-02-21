/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_extends.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:06:46 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 19:06:52 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		print_end_hexa(size_t count, void *ptr, int i)
{
	if (count > 0)
	{
		i = 0;
		while (i + count < 16)
		{
			ft_putstr("   ");
			i++;
		}
		ft_putstr(" | ");
		print_ascii(count, ptr - count);
		ft_putstr("\n");
	}
	return (i);
}

size_t	check_count(size_t count, void *ptr)
{
	if (count >= 16)
	{
		ft_putstr(" | ");
		print_ascii(15, ptr - 15);
		ft_putstr("\n");
		count = 0;
	}
	return (count);
}

char	*get_and_print_first(char *tmp, void *ptr)
{
	tmp = ft_itoabase_uint((*(char*)ptr) >> 4, "0123456789ABCDEF");
	if (tmp != NULL)
	{
		ft_putstr(tmp);
		free(tmp);
	}
	else
		ft_putstr("0");
	return (tmp);
}

char	*get_and_print_second(char *tmp, void *ptr)
{
	tmp = ft_itoabase_uint((char)(*(char*)ptr) - \
		(((*(char*)ptr) >> 4) << 4), "0123456789ABCDEF");
	if (tmp != NULL)
	{
		ft_putstr(tmp);
		free(tmp);
	}
	else
		ft_putstr("0");
	return (tmp);
}
