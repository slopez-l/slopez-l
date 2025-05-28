#include <unistd.h>

// Función para imprimir un número entero mediante recursión
// Esta función toma un entero y lo imprime en la salida estándar
// utilizando la función write de Unix, sin usar printf ni sprintf.
// La función maneja números mayores a 9 dividiendo el número
// recursivamente para extraer cada dígito y luego imprimirlos en orden.
void    ft_print_nbr(int i)
{
    char    *digits;

    digits = "0123456789";           // Array con los dígitos del 0 al 9
    if (i > 9)                       // Si el número es mayor que 9, llamamos recursivamente
        ft_print_nbr(i / 10);        // Dividimos para extraer los dígitos anteriores
    write(1, &digits[i % 10], 1);    // Imprimimos el último dígito
}

// Función principal que imprime números del 1 al 100
// Esta función itera desde 1 hasta 100 e imprime "fizz" si el número es múltiplo de 3,
// "buzz" si es múltiplo de 5, "fizzbuzz" si es múltiplo de ambos, o el número mismo
// si no es múltiplo de ninguno. Utiliza la función ft_print_nbr para imprimir los números.
int main(void)
{
    int i;

    i = 1;                           // Inicializamos la variable en 1
    while (i <= 100)                 // Iteramos desde 1 hasta 100
    {
        if ((i % 3 == 0) && (i % 5 == 0)) // Si es múltiplo de 3 y 5, imprimimos "fizzbuzz"
            write(1, "fizzbuzz\n", 9);
        else if ((i % 3) == 0)        // Si es múltiplo de 3, imprimimos "fizz"
            write(1, "fizz\n", 5);
        else if ((i % 5) == 0)        // Si es múltiplo de 5, imprimimos "buzz"
            write(1, "buzz\n", 5);
        else                          // Si no es múltiplo de ninguno, imprimimos el número
        {
            ft_print_nbr(i);          // Llamamos a la función para imprimir el número
            write(1, "\n", 1);        // Nueva línea después del número
        }
        i++;                          // Incrementamos el contador
    }
    return (0);                       // Retorno exitoso del programa
}

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write

Escribe un programa que imprima los números del 1 al 100,
 cada uno separado por un
nueva línea.
Si el número es múltiplo de 3, en su lugar imprime 'fizz'.
Si el número es múltiplo de 5, en su lugar imprime "buzz".
Si el número es múltiplo de 3 y múltiplo de 5, en su lugar imprime 'fizzbuzz'.

Example:
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>

Ejemplo de ft_print_nbr
Para  ft_print_nbr(123)

Paso 01 123 mayor de 9 lo divido entre 10 --> 12,3
 y llamo de nuevo a la función luego continuara con i = 123.
Paso 02 12 (12,3 en int es 12) mayor de 9 lo divido
entre 10 --> 1,2 y llamo de nuevo a la función luego
 continuara con i = 12.
Paso 03 1 (1,2 en int es 1) menor de 9 -- > write
(1, &digits[1 % 10], 1) el resto de la división es "1".

La función regresa a la llamada anterior
(con i = 12) --> write(1, &digits[12 % 10], 1) el
resto de la división es "2".

La función regresa a la llamada anterior (
con i = 123) --> write(1, &digit
