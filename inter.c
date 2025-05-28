#include <unistd.h>

// Verifica si el carácter `c` ya apareció antes en `str` hasta la posición `i`
int ft_single_in_param(char *str, char c, int i)
{
    int j;

    j = 0;
    while (str[j] != '\0' && j < i)    // Recorre `str` hasta la posición `i`
    {
        if (str[j] == c)              // Si el carácter ya apareció, retorna 1
            return (1);
        j++;
    }
    return (0);                        // Retorna 0 si el carácter es único
}

// Verifica si el carácter `c` está presente en la cadena `str`
int ft_in_other_param(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')            // Recorre toda la cadena `str`
    {
        if (str[i] == c)              // Si el carácter está presente, retorna 1
            return (1);
        i++;
    }
    return (0);                        // Retorna 0 si el carácter no está en `str`
}

// Función principal que imprime los caracteres únicos de `argv[1]` que están en `arg	v[2]`
int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)                    // Verifica que haya exactamente dos argumentos
    {
        while (argv[1][i] != '\0')    // Recorre la primera cadena `argv[1]`
        {
            // Si el carácter es único en `argv[1]` y está en `argv[2]`, lo imprime
            if ((ft_single_in_param(argv[1], argv[1][i], i) == 0)
                && (ft_in_other_param(argv[2], argv[1][i]) == 1))
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);                 // Imprime un salto de línea al final
    return (0);                        // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write

Escribe un programa que tome dos cadenas y muestre, sin dobles, el
caracteres que aparecen en ambas cadenas, en el orden en que
aparecen en la primera uno.
La pantalla será seguida por un \n.
Si el número de argumentos no es 2, el programa muestra \n.

Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
