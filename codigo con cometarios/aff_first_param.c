#include <unistd.h>

// Programa que imprime el primer argumento de la línea de comandos
// seguido de un salto de línea. Si no se proporciona ningún argumento,
// simplemente imprime un salto de línea.
int main(int argc, char **argv)
{
    int i;

    i = 0;
    // Verifica que haya al menos un argumento proporcionado
    if (argc > 1)
    {
        // Recorre la cadena del primer argumento (argv[1])
        while (argv[1][i])
        {
            // Escribe cada carácter en la salida estándar
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    // Escribe un salto de línea al final, independientemente de los argumentos
    write(1, "\n", 1);
    return (0);
}

/*
Assignment name  : aff_first_param
Expected files   : aff_first_param.c
Allowed functions: write

Escribe un programa que tome cadenas como argumentos y muestre su primer
argumento seguido de un \n.
Si el número de argumentos es menor que 1, el programa muestra \n.

Example:
$> ./aff_first_param vincent mit "l'ane" dans un pre et "s'en" vint | cat -e
vincent$
$> ./aff_first_param "j'aime le fromage de chevre" | cat -e
j'aime le fromage de chevre$
$> ./aff_first_param | cat -e
$
*/
