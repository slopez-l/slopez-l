#include <unistd.h>

// Función que encuentra y escribe la última palabra en la cadena
// Esta función toma una cadena de caracteres (str) y escribe la última palabra
// en la salida estándar. La última palabra se define como la secuencia de caracteres
// que aparece después del último espacio o tabulación en la cadena. Si la cadena
// termina con espacios o tabulaciones, estos se ignoran al determinar el inicio de la última palabra.
void    ft_last_word(char *str)
{
    int i;
    int start;
    int end;

    i = 0;
    while (str[i])                // Avanza hasta el final de la cadena
        i++;
    while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t'))
        i--;                      // Retrocede ignorando espacios finales
    end = i;                      // Marca el final de la última palabra
    while (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t')
        i--;                      // Retrocede hasta encontrar el inicio de la última palabra
    start = i;                    // Marca el inicio de la última palabra
    while (start < end)           // Escribe la última palabra carácter por carácter
    {
        write(1, &str[start], 1);
        start++;
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// llama a la función `ft_last_word` para imprimir la última palabra de ese argumento.
int main(int argc, char **argv)
{
    if (argc == 2)                 // Verifica que haya exactamente un argumento
        ft_last_word(argv[1]);      // Llama a la función para procesar la cadena
    write(1, "\n", 1);              // Imprime una nueva línea al final
    return (0);                     // Retorna 0 indicando ejecución exitosa
}

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write

Escribe un programa que tome una cadena y muestre su última
 palabra seguida
de \n.
Una palabra es una sección de cadena delimitada por
espacios/tabulaciones o
por el inicio/final de la cadena.
Si el número de parámetros no es 1 o no hay palabras,
muestre una nueva línea.

Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta,
 then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
