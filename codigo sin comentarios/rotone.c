/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:24:00 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 19:27:02 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] < 'Z')
			|| (str[i] >= 'a' && str[i] < 'z'))
			str[i] += 1;
		else if (str[i] == 'Z')
			str[i] = 'A';
		else if (str[i] == 'z')
			str[i] = 'a';
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write

Escribe un programa que tome una cadena y la muestre,
reemplazando cada uno de sus
letras por la siguiente en orden alfabético.
'z' se convierte en 'a' y 'Z' se convierte en 'A'.
El caso no se ve afectado.
La salida irá seguida de un \n.
Si el número de argumentos no es 1, el programa muestra \n.

Example:
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/
