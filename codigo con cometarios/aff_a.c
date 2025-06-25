
#include <unistd.h>

// Función que busca la letra 'a' en la cadena de caracteres
// Esta función toma un puntero a una cadena de caracteres (str) y busca la primera aparición
// de la letra 'a'. Si encuentra 'a', la escribe en la salida estándar y termina la función.
void    aff_a(char *str)
{
    int i;

    i = 0;
    while (str[i]) // Recorre la cadena hasta encontrar 'a'
    {
        if (str[i] == 'a')
        {
            write(1, "a", 1); // Escribe 'a' en la salida estándar
            return ; // Termina la función cuando encuentra la primera 'a'
        }
        i++;
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa. Si no se pasa ningún argumento,
// imprime 'a' por defecto. Si se pasa un argumento, llama a la función `aff_a` para buscar 'a' en ese argumento.
int main(int argc, char **argv)
{
    if (argc != 2) // Si el número de argumentos no es 1, imprime 'a' por defecto
        write(1, "a", 1);
    else
        aff_a(argv[1]); // Llama a la función para buscar 'a' en el argumento

    write(1, "\n", 1); // Agrega una nueva línea al final de la salida
    return (0);
}

/*
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write

Escribe un programa que tome un string y muestre el primer cáracter 'a'
que encuentre en él, seguido de una nueva línea. si no hay
caracteres 'a' en el string, el programa simplemente escribe una nueva línea.
Si el número de parámetros no es 1, el programa muestra 'a'
seguido de una nueva línea.

Example:
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/
