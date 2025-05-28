/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:50:48 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 18:56:50 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_last_word(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (str[i])
		i++;
	while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t'))
		i--;
	end = i;
	while (i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t')
		i--;
	start = i;
	while (start < end)
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write

Escribe un programa que tome una cadena y muestre su última
 palabra seguida
de \n.
Una palabra es una sección de cadena delimitada por
espacios/tabulaciones o
por el inicio/final de la cadena.
Si el número de parámetros no es 1 o no hay palabras,
muestre una nueva línea.

Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta,
 then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
