/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:01:53 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 19:05:04 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	while (len > 0)
	{
		len--;
		write(1, &str[len], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write

Escribe un programa que tome una cadena y la muestre al revés
seguido de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea.

Examples:
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/
