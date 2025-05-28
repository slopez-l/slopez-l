#include <stdlib.h>

// Función que calcula la longitud de un número en base 10
// Esta función toma un número entero y devuelve la cantidad de dígitos que tiene.
int ft_nbrlen(int nbr)
{
    int len;

    if (nbr <= 0)                   // Si el número es negativo o 0, cuenta al menos 1 dígito
        len = 1;
    else
        len = 0;
    while (nbr)                      // Divide el número por 10 hasta que sea 0
    {
        len++;                        // Incrementa la longitud por cada división
        nbr /= 10;
    }
    return (len);                     // Retorna la cantidad de dígitos
}

// Copia hasta `n` caracteres de `src` en `dest` y añade terminación `\0`
char    *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n && src[i] != '\0')   // Copia los caracteres de `src` a `dest`
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';                   // Asegura que la cadena termine en `\0`
    return (dest);                     // Retorna el puntero a `dest`
}

// Convierte un número entero en una cadena de caracteres (`itoa` - integer to ASCII)
char    *ft_itoa(int nbr)
{
    int     len;
    char    *str;

    len = ft_nbrlen(nbr);              // Calcula la cantidad de dígitos del número
    str = (char *)malloc(sizeof(char) * (len + 1));  // Reserva memoria para la cadena
    if (!str)                          // Verifica si `malloc` ha fallado
        return (NULL);
    str[len] = '\0';                   // Asegura que la cadena termine en `\0`
    if (nbr == -2147483648)            // Caso especial para el valor mínimo de `int`
        return (ft_strncpy(str, "-2147483648", 11));
    if (nbr < 0)                       // Si el número es negativo, lo convierte a positivo
    {
        str[0] = '-';                   // Añade el signo negativo
        nbr = -nbr;
    }
    while (len-- && nbr)               // Llena la cadena con los dígitos del número
    {
        str[len] = (nbr % 10) + '0';    // Convierte el dígito numérico a carácter
        nbr /= 10;
    }
    return (str);                       // Retorna la cadena resultante
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(12));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-4));
	printf("%s\n", ft_itoa(-23));
	return (0);
}*/

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc

Escribe una función que tome un int y lo convierta en una cadena terminada en nulo.
La función devuelve el resultado en una matriz de caracteres que debes asignar.
Su función debe declararse de la siguiente manera:
char *ft_itoa(int nbr);
*/

/*
Truco para obtener el número max INT
un "int" esta formado por 32 bits
Positivos y negativos (enteros con signo): del -2147483648 al 2147483647

En un terminal ejecuta "bc"  (Basic Calculator)
pones 2 ^ 31 y obtienes 2147483648
para salir "quit"
*/
