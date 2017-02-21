/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 17:47:00 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/21 19:16:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int	main(int argc, char **argv)
{
	char *slt = malloc(42);
	slt[0] = 'a';
	slt[1] = 'b';
	char *bjr = malloc(42);
	bjr[0] = 'c';
	bjr[1] = 'c';
	show_hexa_tiny();
	show_alloc_mem();
	return (0);
}
