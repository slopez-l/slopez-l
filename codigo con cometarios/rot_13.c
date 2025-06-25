#include <unistd.h>

// Función que aplica el cifrado ROT-13 a una cadena y la imprime
// Esta función toma una cadena de caracteres (str) y aplica el cifrado ROT-13,
// que consiste en desplazar cada letra 13 posiciones en el alfabeto. Las letras mayúsculas
// y minúsculas se manejan por separado, y los caracteres que no son letras se dejan sin cambios.
void    rot_13(char *str)
{
    int i;

    i = 0;
    while (str[i])                     // Recorre toda la cadena de entrada
    {
        if ((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z'))
        {                               // Comprueba si el carácter es una letra
            if ((str[i] >= 'A' && str[i] <= 'M')
                || (str[i] >= 'a' && str[i] <= 'm'))
                str[i] += 13;           // Aplica ROT-13 sumando 13 posiciones
            else
                str[i] -= 13;           // Aplica ROT-13 restando 13 posiciones
        }
        write(1, &str[i], 1);           // Escribe el carácter cifrado en la salida estándar
        i++;
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// llama a la función `rot_13` para aplicar el cifrado ROT-13 a ese argumento.
int main(int argc, char **argv)
{
    if (argc == 2)                      // Verifica que haya exactamente un argumento
        rot_13(argv[1]);                 // Llama a la función para procesar la cadena
    write(1, "\n", 1);                   // Imprime una nueva línea al final
    return (0);                          // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write

Escribe un programa que tome una cadena y la muestre,
reemplazando cada uno de sus
letras por letra 13 espacios adelante en orden alfabético.
'z' se convierte en 'm' y 'Z' se convierte en 'M'. El caso no se ve afectado.
La salida irá seguida de una nueva línea.
Si el número de argumentos no es 1, el programa muestra una nueva línea.

Example:
$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/
