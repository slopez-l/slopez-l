/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:34:23 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 16:39:55 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
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
