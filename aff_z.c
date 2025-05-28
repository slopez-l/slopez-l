/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slopez-l <slopez-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:54:39 by slopez-l          #+#    #+#             */
/*   Updated: 2025/05/26 19:53:46 by slopez-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	write(1, "z\n", 2);
	return (0);
}

// NO TE OLVIDES EN ESTE CASO DE PONER "2" O PONERLO ASI
// write(1, "z", 1);
// write(1, "\n", 1);

/*
Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write

Escribe un programa que tome una cadena y muestre la primera 'z'
carácter que encuentra en él, seguido de una nueva línea. si no hay
caracteres 'z' en la cadena, el programa escribe 'z' seguido
por una nueva línea. Si el número de parámetros no es 1, el programa muestra
'z' seguida de una nueva línea.

Example:
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
z$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
*/
