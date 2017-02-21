#include "ft_malloc.h"
int main() 
{ 
	int i; 
	char *addr; 
	char *addr2;

	i = 0; 
	while (i < 1024) 
	{
		addr = malloc(104);
		//addr2 = malloc(2048);
		free(addr);
		free(addr2);
		i++;
	}
	show_alloc_mem();
	//show_hexa_tiny();
	return (0); 
} 
