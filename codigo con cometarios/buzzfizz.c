#include <unistd.h>

// Función que imprime un número entero utilizando recursión
void    ft_print_nbr(int i)
{
    char    *digits;

    digits = "0123456789"; // Definimos los caracteres numéricos
    if (i > 9) // Si el número tiene más de un dígito, llamamos recursivamente
        ft_print_nbr(i / 10);
    write(1, &digits[i % 10], 1); // Escribimos el último dígito
}

// Función principal que imprime números del 1 al 100
int main(void)
{
    int i;

    i = 1;
    while (i < 101) // Iteramos de 1 a 100
    {
        // Si el número es múltiplo de 28, imprimimos "fizzbuzz"
        if ((i % 28) == 0)
            write(1, "fizzbuzz", 8);
        // Si es múltiplo de 7, imprimimos "buzz"
        else if ((i % 7) == 0)
            write(1, "buzz", 4);
        // Si es múltiplo de 4, imprimimos "fizz"
        else if ((i % 4) == 0)
            write(1, "fizz", 4);
        // Si no es múltiplo de ninguno, imprimimos el número
        else
            ft_print_nbr(i);
        write(1, "\n", 1); // Nueva línea tras cada salida
        i++;
    }
    return (0);
}

/*
Ejemplo de ft_print_nbr
Para  ft_print_nbr(123)

Paso 01 123 mayor de 9 lo divido entre 10 --> 12,3 y
llamo de nuevo a la función luegocontinuara con i = 123.
Paso 02 12 (12,3 en int es 12) mayor de 9 lo divido
entre 10 --> 1,2 y llamo de nuevo a la función luego
continuara con i = 12. Paso 03 1 (1,2 en int es 1) menor
 de 9 -- > write(1, &digits[1 % 10], 1) el resto de
la división es "1".

La función regresa a la llamada anterior
(con i = 12) --> write(1, &digits[12 % 10], 1)
 el resto de la división es "2".

La función regresa a la llamada anterior
(con i = 123) --> write(1, &digits[123 % 10], 1)
 el resto de la división es "3".

*/
/*
Assignment name  : buzz
Expected files   : buzzfizz.c
Allowed functions: write

Escribe un programa que imprima los números del 1 al 100,
 cada uno separado por un nueva línea.
Si el número es múltiplo de 4, en su lugar imprime 'buzz'.
Si el número es múltiplo de 7, en su lugar imprime "fizz".
Si el número es múltiplo de 4 y múltiplo de 7, en su lugar imprime 'buzzfizz'.

Example:
$>./buzzfizz
1
2
3
buzz
5
6
fizz
buzz
9
10
11
buzz
13
fizz
15
buzz
17
18
19
buzz
fizz
22
23
buzz
25
26
27
fizzbuzz
29
30
[...]
97
fizz
99
buzz
$>
*/
