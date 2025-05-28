#include <unistd.h>

// Programa que imprime el primer argumento de la línea de comandos
// seguido de un salto de línea. Si no se proporciona ningún argumento,
// simplemente imprime un salto de línea.
int main(int argc, char **argv)
{
    int i;

    i = 0;
    // Verifica que haya al menos un argumento en la línea de comandos
    if (argc > 1)
    {
        // Recorre cada carácter del último argumento pasado al programa
        while (argv[argc - 1][i])
        {
            // Escribe cada carácter en la salida estándar
            write(1, &argv[argc - 1][i], 1);
            i++;
        }
    }
    // Escribe un salto de línea al final, independientemente de los argumentos
    write(1, "\n", 1);
    return (0);
}

/*
Assignment name  : aff_last_param
Expected files   : aff_last_param.c
Allowed functions: write

Escribe un programa que tome cadenas como argumentos y muestre su último
argumento seguido de una nueva línea.
Si el número de argumentos es menor que 1, el programa muestra una nueva línea.

Examples:
$> ./aff_last_param "zaz" "mange" "des" "chats" | cat -e
chats$
$> ./aff_last_param "j'aime le savon" | cat -e
j'aime le savon$
$> ./aff_last_param | cat -e
$
*/
