#include <unistd.h>

// Función que imprime una cadena en orden inverso
// Esta función toma un puntero a una cadena de caracteres (str) y escribe
// cada carácter de la cadena en la salida estándar en orden inverso.	
void    rev_print(char *str)
{
    int len;

    len = 0;
    while (str[len])            // Calcula la longitud de la cadena
        len++;
    while (len > 0)             // Recorre la cadena en orden inverso
    {
        len--;                  // Decrementa para acceder al último carácter primero
        write(1, &str[len], 1);  // Escribe cada carácter en la salida estándar
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// llama a la función `rev_print` para imprimir la cadena en orden inverso.
int main(int argc, char **argv)
{
    if (argc == 2)              // Verifica que haya exactamente un argumento
        rev_print(argv[1]);      // Llama a la función para procesar la cadena
    write(1, "\n", 1);           // Imprime una nueva línea al final
    return (0);                  // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write

Escribe un programa que tome una cadena y la muestre al revés
seguido de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea.

Examples:
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/
