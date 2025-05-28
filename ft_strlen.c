/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:44:49 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 19:59:12 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_strlen("Hola Mundo"));
	return (0);
}

/*
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:

Escribe una función que devuelva la longitud de una cadena.
Su función debe declararse de la siguiente manera:
int ft_strlen(char *str);
*/
