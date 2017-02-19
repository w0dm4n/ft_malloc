/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 19:28:23 by frmarinh          #+#    #+#             */
/*   Updated: 2017/02/17 19:28:25 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_malloc.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char *coucou = malloc(1024);
	char *coucou1 = malloc(40);
	char *coucou2 = malloc(200000);
	//char *coucou1 = malloc(40);
	coucou[0] = 'a';
	free(coucou);
	free(coucou1);
	//free(coucou2);
	/*int i = 0;
	while (i <= 100)
	{
		malloc(40);
		malloc(5);
		i++;
	}

	i = 0;

	while (i <= 10000)
	{
		malloc(20);
		i++;
	}

	i = 0;

	while (i <= 10000)
	{
		malloc(2048);
		i++;
	}

	i = 0;

	while (i <= 10)
	{
		malloc(10024);
		i++;
	}*/

	/*while (i < 666)
		coucou1[i++] = 'a';
	coucou1[i] = '\0';
	printf("CONTENT: %s, SIZE: %lu, ADRESS: %p, PAGE_SIZE: %d", coucou1, sizeof(coucou1), coucou1, 
		SMALL_ALLOC);
	*/
	show_alloc_mem();
}