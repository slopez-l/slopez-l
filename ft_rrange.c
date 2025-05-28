#include <stdlib.h>

// Función que genera un array de números en orden inverso desde `start` hasta `end`
// Esta función toma dos enteros, `start` y `end`, y devuelve un puntero a un array
// de enteros que contiene todos los números en el rango [end, start] en orden inverso.
int *ft_rrange(int start, int end)
{
    int *range;
    int len;
    int i;

    i = 0;
    if (start > end)                 // Calcula la cantidad de elementos
        len = start - end + 1;
    else
        len = end - start + 1;

    range = (int *)malloc(sizeof(int) * len); // Reserva memoria para el array
    if (!range)                               // Verifica si la asignación de memoria falló
        return (NULL);                         // Retorna NULL en caso de error

    while (i < len)
    {
        range[i++] = end;      // Asigna el valor de `end` en el array
        if (end > start)       // Si `end` es mayor que `start`, decrementa
            end--;
        else                   // Si `end` es menor que `start`, incrementa
            end++;
    }
    return (range);            // Retorna el array generado
}

/*#include <stdio.h>

// Función principal para probar `ft_rrange`
int main(void)
{
    int *numbers;
    int i = 0;
    int start = 0, end = -3;
    int len = (start > end) ? (start - end + 1) : (end - start + 1);

    numbers = ft_rrange(start, end);  // Llamada a la función `ft_rrange`
    while (i < len)
        printf("%d, ", numbers[i++]);  // Imprime cada número del array

    free(numbers);  // Libera la memoria asignada
    return (0);
}
*/

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc

Escribe la siguiente función:
int *ft_rrange(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros,
llenarla con números consecutivos
valores que comienzan al final y terminan al inicio
(¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/
