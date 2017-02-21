/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extends.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:23:05 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 18:23:15 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;

	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(tmp, (size + 1));
	return (tmp);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n)
	{
		*tmp++ = '\0';
		n--;
	}
}

char	*ft_strcat(char *dest, const char *src)
{
	if (!src || !dest)
		return (NULL);
	ft_strcpy(&dest[ft_strlen(dest)], src);
	return (dest);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
