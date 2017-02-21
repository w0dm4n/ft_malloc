/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:48:12 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 16:48:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(long int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}

size_t		ft_strlen(const char *s)
{
	int i;

	if (s == NULL || !s[0])
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_itoabase_uint(unsigned long int nbr, char *base)
{
	char				*res;
	unsigned long int	size;
	unsigned long int	len;
	unsigned long int	tmp;

	tmp = nbr;
	len = 1;
	size = 0;
	while ((tmp = tmp / ft_strlen(base)))
	{
		len = len * ft_strlen(base);
		size++;
	}
	tmp = nbr;
	res = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (len)
	{
		res[size] = base[(tmp / len)];
		tmp = tmp - ((tmp / len) * len);
		len = len / ft_strlen(base);
		size++;
	}
	res[size] = '\0';
	return (res);
}
