#include <stdio.h>

int main(void)
{
    char **split = ft_split("  esto es una  prueba  ");
    int cont = 0;

    while (split[cont])
    {
		printf("Palabra %d: %s\n", cont + 1, split[cont]);
		cont++;
	}
    return (0);
}
