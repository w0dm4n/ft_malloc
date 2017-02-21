/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:03:47 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 17:03:49 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

char	*set_lowercase(char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (string[i] >= 'A' && string[i] <= 'Z')
			string[i] += 32;
		i++;
	}
	return (string);
}

char	*get_addr(void *ptr)
{
	char	*adress;

	if (!(adress = ft_strnew(15)))
		return (NULL);
	adress[0] = '\0';
	adress = ft_strcat(adress, "0x");
	adress = ft_strcat(adress, \
		set_lowercase(ft_itoabase_uint((unsigned long int)ptr, \
			"0123456789ABCDEF")));
	return (adress);
}
