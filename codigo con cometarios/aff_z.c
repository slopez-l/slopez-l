#include <unistd.h>

// Programa que imprime el primer argumento de la línea de comandos
// seguido de un salto de línea. Si no se proporciona ningún argumento,
// simplemente imprime un salto de línea.
int main(void)
{
    // Escribe la letra 'z' seguida de una nueva línea en la salida estándar
    write(1, "z\n", 2);

    // Retorna 0 para indicar que el programa se ejecutó correctamente
    return (0);
}

// NO TE OLVIDES EN ESTE CASO DE PONER "2" O PONERLO ASI
// write(1, "z", 1);
// write(1, "\n", 1);

/*
Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write

Escribe un programa que tome una cadena y muestre la primera 'z'
carácter que encuentra en él, seguido de una nueva línea. si no hay
caracteres 'z' en la cadena, el programa escribe 'z' seguido
por una nueva línea. Si el número de parámetros no es 1, el programa muestra
'z' seguida de una nueva línea.

Example:
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
z$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
*/
