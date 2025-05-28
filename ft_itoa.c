/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:05:29 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 20:02:18 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_nbrlen(int nbr)
{
	int	len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == -2147483648)
		return (ft_strncpy(str, "-2147483648", 11));
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (len-- && nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
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
