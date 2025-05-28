#include <stdlib.h>

// Función que genera un array de números desde `start` hasta `end`
// Esta función toma dos enteros, `start` y `end`, y devuelve un puntero a un array
// de enteros que contiene todos los números en el rango [start, end].
int *ft_range(int start, int end)
{
    int *range;
    int len;
    int i;

    i = 0;
    if (start > end)                 // Calcula el tamaño del array basado en el rango
        len = start - end + 1;
    else
        len = end - start + 1;

    range = (int *)malloc(sizeof(int) * len); // Reserva memoria para el array
    if (!range)                               // Verifica si la asignación de memoria falló
        return (NULL);                         // Retorna NULL en caso de error

    while (i < len)
    {
        range[i++] = start;       // Asigna el valor de `start` en el array
        if (start > end)          // Si `start` es mayor que `end`, decrementa
            start--;
        else                      // Si `start` es menor que `end`, incrementa
            start++;
    }
    return (range);               // Retorna el array generado
}

/*#include <stdio.h>

// Función principal para probar `ft_range`
int main(void)
{
    int *numbers;
    int i = 0;
    int start = 0, end = -3;
    int len = (start > end) ? (start - end + 1) : (end - start + 1);

    numbers = ft_range(start, end);  // Llamada a la función `ft_range`
    while (i < len)
        printf("%d, ", numbers[i++]);  // Imprime cada número del array

    free(numbers);  // Libera la memoria asignada
    return (0);
}
*/

/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc

Escribe la siguiente función:
int *ft_range(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros, llenarla con números consecutivos
valores que comienzan al principio y terminan al final (¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
