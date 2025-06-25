#include <unistd.h>

// Función que calcula la longitud de una cadena de caracteres
// Esta función toma un puntero a una cadena de caracteres (str) y devuelve
// un entero que representa la cantidad de caracteres en la cadena, excluyendo
// el carácter nulo de terminación '\0'. Es útil para determinar el tamaño de
// una cadena antes de realizar operaciones como impresión o copia.
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')  // Recorre la cadena hasta encontrar el carácter nulo '\0'
        i++;                // Incrementa el contador por cada carácter encontrado
    return (i);             // Retorna la longitud total de la cadena
}

/*#include <stdio.h>

// Función principal para probar `ft_strlen`
int main(void)
{
    printf("%d", ft_strlen("Hola Mundo"));  // Llama a la función e imprime el resultado
    return (0);                             // Retorna 0 indicando ejecución exitosa
}
*/

/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:

Escribe una función que devuelva la longitud de una cadena.
Su función debe declararse de la siguiente manera:
int ft_strlen(char *str);
*/
