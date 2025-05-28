#include <unistd.h>

// Verifica si un carácter es un espacio, tabulación o nueva línea
int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

// Expande los espacios entre palabras a exactamente tres espacios
// Esta función toma una cadena de caracteres y reemplaza cada secuencia de espacios
// por exactamente tres espacios, asegurando que las palabras estén separadas adecuadamente.
void    expand_str(char *str)
{
    int i;

    i = 0;
    while (str[i] && is_space(str[i])) // Ignora los espacios iniciales
        i++;
    while (str[i])
    {
        if (is_space(str[i]))           // Si encuentra espacios, los reemplaza por "   "
        {
            while (str[i] && is_space(str[i])) // Salta todos los espacios consecutivos
                i++;
            if (str[i])                  // Si aún hay texto, inserta los tres espacios
                write(1, "   ", 3);
        }
        if (str[i])                      // Imprime cada carácter de la palabra
        {
            write(1, &str[i], 1);
            i++;
        }
    }
}

// Función principal que procesa los argumentos de la línea de comandos
// Esta función verifica si se ha pasado un único argumento al programa y, si es así,
// llama a la función `expand_str` para expandir los espacios en esa cadena.
int main(int argc, char **argv)
{
    if (argc == 2)                     // Verifica que haya exactamente un argumento
        expand_str(argv[1]);            // Llama a la función de expansión
    write(1, "\n", 1);                  // Imprime un salto de línea al final
    return (0);                         // Retorna 0 para indicar ejecución exitosa
}

/*
Escribe un programa que tome una cadena y
la muestre exactamente con tres espacios.
entre cada palabra, sin espacios ni tabulaciones
ni al principio ni al final,seguido de una nueva línea.
Una palabra es una sección de cadena delimitada por
espacios/tabulaciones o por el inicio/final de la cadena.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre
una nueva línea.

Examples:
$> ./expand_str "vous   voyez   c'est   facile   d'afficher
   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/
