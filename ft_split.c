#include <stdlib.h>

// Verifica si un carácter es un espacio en blanco, tabulación o nueva línea
int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));  // Retorna 1 si el carácter es un espacio
}

// Cuenta cuántas palabras hay en la cadena
// Esta función recorre la cadena y cuenta las palabras, ignorando espacios
// al inicio y al final, así como los espacios entre palabras.
int ft_count_words(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])                           // Recorre toda la cadena
    {
        while (str[i] && is_space(str[i]))   // Ignora espacios iniciales
            i++;
        if (str[i])                          // Si hay un carácter válido, incrementa el contador
            count++;
        while (str[i] && !is_space(str[i]))  // Avanza hasta el final de la palabra
            i++;
    }
    return (count);                          // Retorna el número total de palabras
}

// Copia una palabra desde la posición 'start' hasta 'end' en una nueva cadena
char    *ft_word_dup(char *str, int start, int end)
{
    char    *word;
    int     i;

    word = (char *)malloc(sizeof(char) * (end - start + 1));  // Reserva memoria para la palabra
    i = 0;
    if (!word)                                 // Verifica si 'malloc' falló
        return (NULL);
    while (start < end)                        // Copia cada carácter de la palabra
        word[i++] = str[start++];
    word[i] = '\0';                            // Agrega el terminador de cadena
    return (word);                             // Retorna la nueva palabra duplicada
}

// Divide la cadena en palabras y devuelve un array de cadenas
char    **ft_split(char *str)
{
    char    **split;
    int     i;
    int     j;
    int     start;

    i = 0;
    j = 0;
    split = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));  // Reserva memoria para el array
    if (!split)                              // Verifica si 'malloc' falló
        return (NULL);
    while (str[i])                           // Recorre la cadena
    {
        while (str[i] && is_space(str[i]))   // Ignora espacios iniciales
            i++;
        start = i;                           // Marca el inicio de la palabra
        while (str[i] && !is_space(str[i]))  // Avanza hasta el final de la palabra
            i++;
        if (start != i)                      // Si hay una palabra válida, la guarda en el array
            split[j++] = ft_word_dup(str, start, i);
    }
    split[j] = NULL;                         // Termina el array con NULL
    return (split);                          // Retorna el array de palabras
}

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc

Escribe una función que tome una cadena, la divida en palabras y
 las devuelva como
una matriz de cadenas terminada en NULL.
Una "palabra" se define como parte de una cadena delimitada por
espacios/tabulaciones/nueva
líneas, o por el inicio/final de la cadena.
Su función debe declararse de la siguiente manera:
char **ft_split(char *str);
*/
