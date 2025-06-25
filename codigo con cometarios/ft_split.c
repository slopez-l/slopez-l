#include <unistd.h>
#include <stdio.h>

// Función para verificar si un carácter es un espacio
int ft_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13)); // Devuelve `true` si es un espacio o tabulación
}

// Función para dividir la cadena en palabras separadas por espacios
char **ft_split(char *str)
{
    static char words[4096][4096]; // Matriz estática para almacenar palabras (máximo 4096 palabras con 4096 caracteres cada una)
    static char *split[4096]; // Matriz de punteros para devolver las palabras correctamente
    int contwords = 0; // Contador de palabras encontradas
    int contchars = 0; // Contador de caracteres dentro de cada palabra
    int cont = 0; // Índice para recorrer la cadena `str`

    while (str[cont] && ft_space(str[cont])) // Saltar espacios iniciales
        cont++;

    while (str[cont]) // Recorrer la cadena hasta el final
    {
        if (ft_space(str[cont]) && contchars > 0) // Si encuentra un espacio después de una palabra
        {
            words[contwords][contchars] = '\0'; // Terminar la palabra con `\0`
            split[contwords] = words[contwords]; // Guardar la palabra en `split`
            contwords++; // Aumentar el contador de palabras
            contchars = 0; // Reiniciar el contador de caracteres para la siguiente palabra
        }
        else if (!ft_space(str[cont])) // Si el carácter no es un espacio, lo agrega a la palabra actual
            words[contwords][contchars++] = str[cont];

        cont++; // Pasar al siguiente carácter en `str`
    }

    if (contchars > 0) // Si hay una última palabra pendiente de cerrar
    {
        words[contwords][contchars] = '\0'; // Terminar la palabra con `\0`
        split[contwords] = words[contwords]; // Guardar la última palabra
        contwords++;
    }

    split[contwords] = NULL; // Finalizar el array con `NULL`
    return split; // Devolver el array de palabras
}

// Función principal para probar `ft_split()`
int main(void)
{
    char **split = ft_split("  esto es una  prueba  "); // Cadena a dividir
    int cont = 0; // Contador para recorrer el array de palabras

    while (split[cont]) // Iterar sobre las palabras hasta que `NULL` marque el fin
    {
        printf("Palabra %d: %s\n", cont + 1, split[cont]); // Imprimir cada palabra con su número
        cont++; // Pasar a la siguiente palabra
    }

    return (0); // Indicar que el programa terminó correctamente
}
