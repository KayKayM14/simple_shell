#include <stdio.h>

int main(int ac, char **av)
{
	int i;
/*start from av[0] and print each argument until a NULL pointer is found*/
	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
