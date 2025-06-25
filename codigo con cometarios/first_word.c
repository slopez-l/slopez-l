#include <unistd.h>

// Función que encuentra y escribe la primera palabra de la cadena
// Esta función toma una cadena de caracteres (str) y escribe la primera palabra
// en la salida estándar. La primera palabra se define como la secuencia de caracteres
// que aparece antes del primer espacio, tabulación o nueva línea. Si la cadena comienza
// con espacios o tabulaciones, estos se ignoran al determinar el inicio de la primera palabra.
void    first_word(char *str)
{
    int i;

    i = 0;
    // Salta los espacios en blanco, tabulaciones y nuevas líneas iniciales
    while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
        i++;
    // Escribe la primera palabra hasta encontrar un espacio o fin de cadena
    while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
    {
        write(1, &str[i], 1);  // Escribe cada carácter de la palabra
        i++;
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// llama a la función `first_word` para imprimir la primera palabra de ese argumento.
int main(int argc, char **argv)
{
    // Verifica que se haya pasado un único argumento
    if (argc == 2)
        first_word(argv[1]);  // Llama a la función para procesar la cadena
    write(1, "\n", 1);        // Imprime una nueva línea al final
    return (0);               // Retorna 0 indicando ejecución exitosa
}

/*
Escribe un programa que tome una cadena y muestre su primera palabra, seguida
de una nueva línea.
Una palabra es una sección de cadena delimitada por espacios/tabulaciones o
por el inicio/final de la cuerda.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre
una nueva línea.

Examples:
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again,
 maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
