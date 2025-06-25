#include <unistd.h>

// Función que aplica una rotación de +1 a cada letra en la cadena
// Esta función toma una cadena de caracteres (str) y modifica cada letra
// avanzándola una posición en el alfabeto. Si la letra es 'Z' o 'z',
// se convierte en 'A' o 'a' respectivamente. Los caracteres que no son letras
// se dejan sin cambios. La función escribe el resultado directamente en la salida estándar.
void    rotone(char *str)
{
    int i;

    i = 0;
    while (str[i])                     // Recorre la cadena de entrada
    {
        if ((str[i] >= 'A' && str[i] < 'Z')
            || (str[i] >= 'a' && str[i] < 'z'))
            str[i] += 1;               // Avanza la letra en una posición
        else if (str[i] == 'Z')
            str[i] = 'A';              // Si es 'Z', vuelve a 'A'
        else if (str[i] == 'z')
            str[i] = 'a';              // Si es 'z', vuelve a 'a'
        write(1, &str[i], 1);           // Escribe el carácter modificado en la salida estándar
        i++;
    }
}

// // Función principal que procesa los argumentos de la línea de comandos
// // Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// // llama a la función `rotone` para aplicar la rotación a ese argumento.
int main(int argc, char **argv)
{
    if (argc == 2)                      // Verifica que haya exactamente un argumento
        rotone(argv[1]);                 // Llama a la función para procesar la cadena
    write(1, "\n", 1);                   // Imprime una nueva línea al final
    return (0);                          // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write

Escribe un programa que tome una cadena y la muestre,
reemplazando cada uno de sus
letras por la siguiente en orden alfabético.
'z' se convierte en 'a' y 'Z' se convierte en 'A'.
El caso no se ve afectado.
La salida irá seguida de un \n.
Si el número de argumentos no es 1, el programa muestra \n.

Example:
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/
