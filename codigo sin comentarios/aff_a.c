/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:15:12 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/23 11:32:36 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aff_a(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
		{
			write(1, "a", 1);
			return ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "a", 1);
	else
		aff_a(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write

Escribe un programa que tome un string y muestre el primer cáracter 'a'
que encuentre en él, seguido de una nueva línea. si no hay
caracteres 'a' en el string, el programa simplemente escribe una nueva línea.
Si el número de parámetros no es 1, el programa muestra 'a'
seguido de una nueva línea.

Example:
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/
