#include <unistd.h>

// Función que imprime una cadena de caracteres en la salida estándar
// Esta función toma un puntero a una cadena de caracteres (str) y escribe
// cada carácter de la cadena en la salida estándar (normalmente la consola).
void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')    // Recorre la cadena hasta encontrar el carácter nulo '\0'
        write(1, &str[i++], 1); // Escribe cada carácter en la salida estándar
}

/*int main(void)
{
	ft_putstr("Hola, 42!");
	write(1, "\n", 1);
	return (0);
}*/
/*
 Assignment name  : ft_putstr
 Expected files   : ft_putstr.c
 Allowed functions: write

Escribe una función que muestre una cadena en la salida estándar.
El puntero pasado a la función contiene la dirección del primer caracter de la
cadena.
Su función debe declararse de la siguiente manera:
void ft_putstr(char *str);
*/
