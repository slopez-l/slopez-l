#include <stdlib.h>

// Calcula la cantidad de dígitos en el número, incluyendo el signo negativo si es necesario
static int  ft_nbrlen(int n)
{
    int len = (n <= 0); // Si n es negativo o cero, se necesita al menos un carácter (signo '-' o '0')

    while (n) // Mientras haya dígitos en el número
        n /= 10, len++; // Divide entre 10 para eliminar el último dígito y aumenta la longitud
    return (len); // Retorna la cantidad total de caracteres necesarios
}

char    *ft_itoa(int n)
{
    char    *str;
    int     len = ft_nbrlen(n); // Obtiene la longitud necesaria para la cadena
    long    nb = n; // Se usa `long` para evitar problemas con INT_MIN (-2147483648)

    str = (char *)malloc(len + 1); // Reserva memoria para la cadena (+1 para el '\0')
    if (!str) // Si falla `malloc`, retorna NULL
        return (NULL);
    str[len] = '\0'; // Asigna el carácter de fin de cadena

    if (nb < 0) // Si el número es negativo
    {
        str[0] = '-'; // Coloca el signo negativo en la primera posición
        nb = -nb; // Convierte el número a positivo para facilitar la conversión
    }

    while (--len >= (str[0] == '-')) // Rellena los dígitos de derecha a izquierda
    {
        str[len] = '0' + (nb % 10); // Extrae el último dígito y lo convierte en carácter
        nb /= 10; // Reduce el número dividiéndolo entre 10
    }

    return (str); // Retorna la cadena con la conversión del número
}
