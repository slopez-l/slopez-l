#include <unistd.h>

// Verifica si el carácter `c` ya apareció en `str` hasta la posición `limit`
// Esta función recorre la cadena `str` hasta el índice `limit` (o toda la cadena si `limit == -1`)
int ft_was_printed(char *str, char c, int limit)
{
    int i;

    i = 0;
    while (str[i] && (i < limit || limit == -1))  // Recorre `str` hasta `limit` o toda la cadena si `limit == -1`
    {
        if (str[i] == c)  // Si el carácter ya apareció, retorna 1
            return (1);
        i++;
    }
    return (0);  // Retorna 0 si el carácter no ha sido impreso antes
}

// Escribe la unión de dos cadenas sin repetir caracteres
void    ft_union(char *str1, char *str2)
{
    int i;

    i = 0;
    while (str1[i])  // Recorre la primera cadena `str1`
    {
        if (!ft_was_printed(str1, str1[i], i))  // Si el carácter no ha sido impreso antes, lo escribe
            write(1, &str1[i], 1);
        i++;
    }
    i = 0;
    while (str2[i])  // Recorre la segunda cadena `str2`
    {
        if (!ft_was_printed(str1, str2[i], -1)  // Verifica que no esté en `str1`
            && !ft_was_printed(str2, str2[i], i))  // Verifica que no se haya repetido en `str2`
            write(1, &str2[i], 1);
        i++;
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se han pasado exactamente dos argumentos al programa y, si es así,
// llama a la función `ft_union` para imprimir la unión de los caracteres de ambos argumentos.
int main(int argc, char **argv)
{
    if (argc == 3)  // Verifica que haya exactamente dos argumentos
        ft_union(argv[1], argv[2]);  // Llama a la función para unir las cadenas
    write(1, "\n", 1);  // Imprime un salto de línea al final
    return (0);  // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write

Escribe un programa que tome dos cadenas y muestre, sin dobles, el
caracteres que aparecen en cualquiera de las cadenas.
La pantalla se mostrará en el orden en que aparecen los caracteres en la línea
de comando y irá seguido de un \n.
Si el número de argumentos no es 2, el programa muestra \n.

Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
