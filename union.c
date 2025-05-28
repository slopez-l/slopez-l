/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:35:45 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 19:48:40 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_was_printed(char *str, char c, int limit)
{
	int	i;

	i = 0;
	while (str[i] && (i < limit || limit == -1))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (!ft_was_printed(str1, str1[i], i))
			write(1, &str1[i], 1);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (!ft_was_printed(str1, str2[i], -1)
			&& !ft_was_printed(str2, str2[i], i))
			write(1, &str2[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write

Escribe un programa que tome dos cadenas y muestre, sin dobles, el
caracteres que aparecen en cualquiera de las cadenas.
La pantalla se mostrará en el orden en que aparecen los caracteres en la línea
de comando y irá seguido de un \n.
Si el número de argumentos no es 2, el programa muestra \n.

Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
