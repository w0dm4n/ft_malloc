#include "ft_malloc.h"
int main() 
{ 
	int i; 
	char *addr; 

	i = 0; 
	while (i < 1024) 
	{
		addr = malloc(1024);
		i++; 
		free(addr);
	}
	show_alloc_mem();
	return (0); 
} 
