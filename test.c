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
	/*char *bjr = malloc(42);
	char *cc = malloc(666);
	free (bjr);
	bjr = malloc(123);
	free(cc);
	free(bjr);*/
	//free(bjr);
	/*char *slt = malloc(42);
	slt[0] = 'a';
	printf("%s\n", slt);
	free(slt);
	slt = malloc(42);
	slt[0] = 'a';
	printf("%s\n", slt);
	int i = 0;
	while (i < 1000)
	{
		slt = malloc(42);
		slt[0] = 'a';
		printf("%s\n", slt);
		free(slt);
		i++;
	}*/
	//char *bjr = malloc(1025);
	//free(bjr);
	/*int i = 0;
	while (i < 1000)
	{
		malloc(1000);
		malloc(42);
		malloc(100000);
		//printf("%d\n", i);
		i++;
	}*/
	int i = 0;
	char *test = malloc(5);
	char *test1 = malloc(10);
	show_alloc_mem();
	char *bonjour;

	bonjour = malloc(5);
	strcpy(bonjour, "test");
	printf("Before reallocation: %s, adress: %p\n", bonjour, bonjour);
	//bonjour = realloc(bonjour, 10);
	printf("After reallocation: %s, adress: %p\n", bonjour, bonjour);
	strcat(bonjour, "coucou");
	printf("Modification: %s\n", bonjour);

	printf("\n\n--- mallocs ---\n\n");
	int total = 0;
	char *str = malloc(42);
	total += 42;
	char *str2 = malloc(42);

	str2 = malloc(1024);
	total += 42;
	char *str6 = malloc(2038);
	char *str11 = malloc(5000);
	total += 5000;
	show_alloc_mem();

	char *str5 = malloc(556);
	total += 556;
	
	i = -1;

	printf("\n\n--- debugging ---\n\n");
	while (++i < 42)
	{
		str[i] = (i % 26)+ 'a';
		str2[i] = ((i + 2) % 26)+ 'a';
		str5[i] = ((i + 2) % 26)+ 'a';
	}
	str[i] = '\0';
	str2[i] = '\0';
	printf("str -> %s\n", str);
	printf("str2 -> %s\n", str2);
	printf("str -> %s\n", str);

	int	y = 0;
	char *str3;


	printf("\n\n--- lots of malloc ---\n\n");
	while ((++y * 42) < 16000)
	{
		str3 = malloc(42);
		total += 42;
		show_alloc_mem();
		printf("total -> %d\n", total);
		i = -1;
		while (++i < 42)
			str3[i] = (i * y  % 26)+ 'a';
		str3[i] = '\0';
		printf("str3 -> %s total -> %d\n", str3, total);
		free(str3);
	}

	printf("end\n");
	//return (0);

	char *coucou = malloc(1024);
	char *coucou1 = malloc(4000000);
	char *coucou2 = malloc(200000);
	char *bjr = NULL;
	char *bjr2 = NULL;
	//char *coucou1 = malloc(40);
	coucou[0] = 'a';
	free(coucou);
	free(coucou1);
	//malloc(40);
	//free(coucou1);
	free(coucou2);
	i = 0;
	while (i < 10000)
	{
		bjr2 = malloc(1025);
		bjr = malloc(40);
		bjr[0] = 'a';
		printf("%s", bjr);
		bjr[0] = '\0';
		free(bjr);
		free(bjr2);
		i++;
	}
	i = 0;
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
	}

	/*while (i < 666)
		coucou1[i++] = 'a';
	coucou1[i] = '\0';
	printf("CONTENT: %s, SIZE: %lu, ADRESS: %p, PAGE_SIZE: %d", coucou1, sizeof(coucou1), coucou1, 
		SMALL_ALLOC);
	*/
	show_alloc_mem();
}